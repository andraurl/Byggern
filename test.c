#include <avr/io.h>
#include "test.h"
#include "UART_driver.h"

void test(void){
    while(1)
    {
        DDRB = 0x08;
        if(PORTB & 0x08){
            clear_bit(PORTB, 3);
        }
        else{
            set_bit(PORTB,3);
        }
    }
}
