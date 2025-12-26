# Simple Makefile for TM4C123G
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
RENODE = /Applications/Renode.app/Contents/MacOS/renode

# Build output directory
BUILD_DIR = build

# Flags for the TM4C123G (Cortex-M4F)
CFLAGS = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS += -g -Os -std=c99 -ffreestanding -nostdlib
CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS = -T link.ld -nostartfiles -Wl,--gc-sections

# Your files
SRCS = main.c UART.c startup.c
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
PROJECT = main

all: $(BUILD_DIR)/$(PROJECT).elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O binary $@ $(BUILD_DIR)/$(PROJECT).bin
	@echo "Build complete: $@"

run: $(BUILD_DIR)/$(PROJECT).elf
	$(RENODE) simulation.resc

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean