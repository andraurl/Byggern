#include <avr/io.h>
#include <stdio.h>

#include "UART_driver.h"

void UART_init(unsigned int ubrr_reg){

    //Set Baudrate; UBRRH 4 MSB, UBRRL: 8 LSB
    UBRRH = (unsigned char) (ubrr_reg>>8);
    UBRRL = (unsigned char) ubrr_reg;
    //Enable receiver and transmitter
    UCSRB = (1<<RXEN) | (1<<TXEN);
    //Set frame format: 8 data, 2 stop bit
    UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
