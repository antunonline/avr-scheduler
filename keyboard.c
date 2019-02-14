#include "keyboard.h"

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__ 1
#endif

#ifndef F_CPU
#define F_CPU=16000000UL
#endif

#include "avr/io.h"


void setOutputsToHigh(void)
{
    // Set ROW pins to output and HIGH
       DDRB |= (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB3) | (1 << PORTB2);
       PORTB |= (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB3) | (1 << PORTB2);
}

void enableInputPullups(void)
{
    // Set Column pins to INPUT with PULL-UP's enabled
    DDRB &= ~((1 << PORTB1) | (1 << PORTB0));
    PORTB |= (1 << PORTB1) | (1 << PORTB0);
    DDRD &= ~((1 << PORTD7) | (1 << PORTD6));
    PORTD |= (1 << PORTD7) | (1 << PORTD6);
}



enum Key keyboard_read_key()
{
    // Scan all keys

          enum Key key = KEY_NONE;

          for (int i = 0; i < 4; i++) {
              switch (i) {
                  case 0:
                      PORTB &= ~(1 << PORTB5);
                      break;
                  case 1:
                      PORTB &= ~(1 << PORTB4);
                      break;
                  case 2:
                      PORTB &= ~(1 << PORTB3);
                      break;
                  case 3:
                      PORTB &= ~(1 << PORTB2);
                      break;
              }

              for (int j = 0, state = 0; j < 4; j++) {
                  switch (j) {
                      case 0:
                          state = PINB & (1 << PORTB1);
                          break;
                      case 1:
                          state = PINB & (1 << PORTB0);
                          break;
                      case 2:
                          state = PIND & (1 << PORTB7);
                          break;
                      case 3:
                          state = PIND & (1 << PORTB6);
                          break;
                  }

                  if (state == 0) {
                      if (j < 3)
                          key = (enum Key)(
                                  i * 3 + j
                          );
                      else
                          key = (enum Key)(
                                  10 + i
                          );
                  }
              }

              setOutputsToHigh();
          }


          return key;
}

void keyboard_init(void)
{
    setOutputsToHigh();
    enableInputPullups();
}
