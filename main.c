#include "UART.h"
#include "tm4c123gh6pm.h"
#include "types.h"

// Simple delay function
void delay(volatile int count) {
  while (count > 0) {
    count--;
  }
}

int main(void) {
  UART_Init();

  UART_OutString("\r\nHello from TM4C123 on Renode!\r\n");

  while (1) {
    delay(1000000);
  }
}