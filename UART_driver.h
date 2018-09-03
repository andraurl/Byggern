#pragma once

void UART_init(unsigned int ubrr_reg);
int UART_Transmit_Char (unsigned char data);
int UART_Receive_Char(void);

#define BAUDRATE 9600
#define FOSC 4915200
#define MYUBRR FOSC/16/BAUDRATE-1

/*
#define set_bit( reg, bit ) (reg |= (1 << bit))
#define clear_bit( reg, bit ) (reg &= ~(1 << bit))
#define test_bit( reg, bit ) (reg & (1 << bit))
#define loop_until_bit_is_set( reg, bit ) while( !test_bit( reg, bit ) )
#define loop_until_bit_is_clear( reg, bit ) while( test_bit( reg, bit ) )
*/
