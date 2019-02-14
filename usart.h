#ifndef USART_HEADER
#define USART_HEADER

void usart_init(unsigned int const baud_rate);
void usart_transmit_char(char const c);
void usart_transmit_string(char const * const str);

#endif
