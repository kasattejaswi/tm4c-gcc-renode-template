#include "UART.h"         // Valvano's UART driver
#include "tm4c123gh6pm.h" // Register definitions
#include "types.h"

// Simple delay function
void delay(volatile int count) {
  while (count > 0) {
    count--;
  }
}

int main(void) {
  UART_Init(); // Initialize UART (Standard Valvano function)

  UART_OutString("\r\nHello from TM4C123 on Renode!\r\n");
  UART_OutString("This program calculates areas of square shaped rooms\r\n");

  // Simple test loop
  while (1) {
    // Your lab logic here - blink or do nothing
    delay(1000000);
  }
}