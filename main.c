// IDE is not recognizing compiler flags, so we will inject them to make completion work
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__ 1
#endif

#ifndef F_CPU
#define F_CPU=16000000UL
#endif

#ifndef BAUD
#define BAUD 19200UL
#endif

#include "avr/io.h"
#include "avr/delay.h"
#include "util/setbaud.h"

int main()
{
    // Write some value to USART

    // Enable transmit
    UCSR0B |= (1<<TXEN0);

    // Write data to transmit buffer
    while(1){
        while(! (UCSR0A & (1<<UDRE0)));
        UDR0 = 'a';
    }

    return 0;
}
