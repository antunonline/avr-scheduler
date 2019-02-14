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


void my_task(void) {
    DDRB |= (1<<PORTB5);

//    usart_transmit_char(0xaa);
   int i = 0;
    while(1){
        usart_transmit_char(0xaa);
    }
}

void my_task_b(void){
    while(1){
        usart_transmit_char(0xbb);
    }
}

void my_task_c(void){
    while(1){
        usart_transmit_char(0xcc);
    }
}

void my_task_d(void){
    while(1){
        usart_transmit_char(0xdd);
    }
}

int main(void){
    // Init usart
    usart_init(19200);

    // Init scheduler
    scheduler_init();

    // Register custom task
    scheduler_register_task(my_task);
    scheduler_register_task(my_task_b);
    scheduler_register_task(my_task_c);
    scheduler_register_task(my_task_d);

    // Store scheduler task
    scheduler_enter();

    while(1){}
}
