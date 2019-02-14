#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__ 1
#endif

#ifndef F_CPU
#define F_CPU=16000000UL
#endif


#include "usart.h"
#include "avr/io.h"

void usart_init(unsigned int const baud_rate)
{
    // Set baud rate
    unsigned int ubbr_value = ((F_CPU)/16/baud_rate - 1UL) & 0xffff;
    UBRR0H = (unsigned char) (ubbr_value >> 8);
    UBRR0L = (unsigned char) ubbr_value;;


    // Enable only transmit
    UCSR0B |= (1<<TXEN0);
}

void usart_transmit_char(char const c)
{
    // Wait until data register empty is set
    while(! (UCSR0A & (1<<UDRE0)));

    // Put data into data register
    UDR0 = (unsigned char) c;
}

void usart_transmit_string(const char * const str)
{
    char const * ptr = str;
    for(; 0 != *ptr; ptr++){
        usart_transmit_char(*ptr);
    }
}
