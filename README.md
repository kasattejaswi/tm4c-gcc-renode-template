# TM4C123GXL Bare-Metal Starter

Bare-metal starter template for TM4C123GXL using Arm GNU Toolchain (GCC), Make, and Renode simulation.

## Prerequisites

- **arm-none-eabi-gcc**: `brew install arm-none-eabi-gcc`
- **Renode**: Download from https://renode.io/

## Usage

```bash
make          # Build
make run      # Build and run in Renode
make clean    # Clean
```

## Project Structure

```
├── main.c              # Application entry point
├── UART.c/h            # UART driver
├── startup.c           # Vector table and reset handler
├── types.h             # Type definitions (uint32_t, etc.)
├── link.ld             # Linker script
├── tm4c123gh6pm.h      # Register definitions
├── tm4c123gh6pm.repl   # Renode platform
├── simulation.resc     # Renode script
└── build/              # Build output
```

## Notes

- Freestanding build (no standard library)
- Use `UART_OutString()` / `UART_OutUDec()` for output
- UART works in Renode; GPIO/Timers are stubbed
