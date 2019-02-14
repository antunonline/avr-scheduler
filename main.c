// IDE is not recognizing compiler flags, so we will inject them to make completion work
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__ 1
#endif

#ifndef F_CPU
#define F_CPU=16000000UL
#endif

#include "avr/io.h"
#include "util/delay.h"
#include "usart.h"
#include "scheduler.h"
#include "avr/interrupt.h"
#include "keyboard.h"


static volatile enum Key key = KEY_NONE;
static volatile enum Key tmpKey = KEY_NONE;
static volatile enum Key lastKey = KEY_NONE;
void task_read_key(void) {
    keyboard_init();
    unsigned char numOccs = 0;
    unsigned char numChanges = 0;

    while(1){
        tmpKey = keyboard_read_key();

        if(tmpKey != lastKey) {
            numChanges ++;
            if(numChanges == 222) {
                lastKey = tmpKey;
                numChanges = 0;
                numOccs = 0;
            }
        } else if(numOccs > 100) {
            numChanges = 0;
        }
        else {
            numChanges = 0;
            numOccs++;
            if(numOccs > 100)
                numOccs = 101;
        }


        if(KEY_NONE != tmpKey && numOccs == 100) {
            key = tmpKey;
            scheduler_yield();
        }
    }
}


void task_transmit_key(void){
    while(1){
        if(key != KEY_NONE) {
            usart_transmit_char((char)key);
            key = KEY_NONE;
        }
        scheduler_yield();
    }
}

int main(void){
    // Init usart
    usart_init(19200);

    // Init scheduler
    scheduler_init();

    // Register custom tasks (max 4)
    scheduler_register_task(task_read_key);
    scheduler_register_task(task_transmit_key);

    // Store scheduler task
    scheduler_enter();

    while(1){}
}
