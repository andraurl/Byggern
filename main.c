#include <stdio.h>

#include "UART_driver.h"

int main (int argc, char *argv[]) {
    UART_Init(MYUBRR);
    while(1){
        UART_Transmit_Char('a');
    }
    return 0;
}
