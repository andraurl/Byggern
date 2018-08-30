#include <avr/io.h>

void test(void){
    while(1)
    {
        PORTB ^= 0x08;
    }
}
