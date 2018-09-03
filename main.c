#include <stdio.h>

#include "UART_driver.h"

void excercise1 (void)
{
    UART_Transmit_Char(UART_Receive_Char());
    printf("/nHei/n");
}

int main (int argc, char *argv[]) {
    UART_Init(MYUBRR);
    //UART_Init(31);
    while(1){
        UART_printf("Hello world!");
    }
    return 0;
}
