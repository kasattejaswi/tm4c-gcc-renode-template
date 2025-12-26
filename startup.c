#include "types.h"

/* Memory addresses defined in the Linker Script */
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;

/* Stack pointer is defined as a symbol in the linker script */
extern uint32_t __stack_top;

/* Function prototypes */
void Reset_Handler(void);
void Default_Handler(void);

/* Weak declarations allow you to override them in main.c */
void __attribute__((weak)) UART0_Handler(void) { Default_Handler(); }
// Add other interrupt handlers here as needed for future labs

/* The Vector Table - This puts the stack and reset handler at the start of
 * memory */
__attribute__((section(".isr_vector"))) void (*const g_pfnVectors[])(void) = {
    (void (*)(void))(
        &__stack_top), // Initial Stack Pointer (cast to function pointer)
    Reset_Handler,     // Reset Handler
    Default_Handler,   // NMI Handler
    Default_Handler,   // Hard Fault Handler
    Default_Handler,   // MPU Fault Handler
    Default_Handler,   // Bus Fault Handler
    Default_Handler,   // Usage Fault Handler
    0, 0, 0, 0,        // Reserved
    Default_Handler,   // SVCall Handler
    Default_Handler,   // Debug Monitor Handler
    0,                 // Reserved
    Default_Handler,   // PendSV Handler
    Default_Handler,   // SysTick Handler

    // External Interrupts (IRQ0 - IRQ15 shown here, extend as needed)
    Default_Handler, // GPIO Port A
    Default_Handler, // GPIO Port B
    Default_Handler, // GPIO Port C
    Default_Handler, // GPIO Port D
    Default_Handler, // GPIO Port E
    UART0_Handler,   // UART0 (We added this one explicitly for your lab!)
    Default_Handler, // UART1
    Default_Handler, // SSI0
    Default_Handler, // I2C0
                     // ... (You can add more if the lab requires them later)
};

/* This function runs when the chip turns on */
void Reset_Handler(void) {
  uint32_t *pSrc, *pDest;

  // 1. Copy .data section from Flash to RAM
  pSrc = &_etext;
  for (pDest = &_data; pDest < &_edata;) {
    *pDest++ = *pSrc++;
  }

  // 2. Zero out the .bss section (uninitialized variables)
  for (pDest = &_bss; pDest < &_ebss;) {
    *pDest++ = 0;
  }

  // 3. Call your main function
  extern int main(void);
  main();
}

/* Default handler for interrupts that don't have a specific function */
void Default_Handler(void) {
  while (1) {
  }
}