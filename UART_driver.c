#include <avr/io.h>
#include <stdio.h>

#include "UART_driver.h"

int UART_Receive_Char(void);
int UART_Transmit_Char (unsigned char data);

FILE uart_fd = FDEV_SETUP_STREAM(UART_Transmit_Char, UART_Receive_Char, _FDEV_SETUP_RW);

void UART_Init(unsigned int ubrr_reg){

    //Set Baudrate; UBRRH 4 MSB, UBRRL: 8 LSB
    UBRR0H = (unsigned char) (ubrr_reg>>8);
    UBRR0L = (unsigned char) ubrr_reg;
    //Enable receiver and transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    //Set frame format: 8 data, 2 stop bit
    UCSR0C = (1<<URSEL0)|(3<<UCSZ00);
}

int UART_Transmit_Char (unsigned char data)
{
    //Wait for empty transmit buffer
    while( !( UCSR0A & (1<<UDRE0)) );

    //Put data into buffer, sends the data
    UDR0 = data;
    return 0;
}

int UART_Receive_Char(void)
{
    //Wait for data
    while(!(UCSR0A & (1<<RXC0)));

    //Get and return data from buffer
    return UDR0;
}
__attribute__((format(printf, 1, 2))) void UART_printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(&uart_fd, fmt, args);
    va_end(args);

}
