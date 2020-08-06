#******************************************************************************
# Copyright (C) 2020 by Cesar Oliveros - Universidad de Carabobo
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile para compilar el proyecto del módulo 2 de Introduction to Embedded
# Systems Software de University of Colorado Boulder en coursera.com
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Target output:
#      c1m2.out
#
# Build Targets:
#      <FILE>.o - builds <FILE>.o object file
#      <FILE>.i - builds <FILE>.i preprocessed file
#      <FILE>.asm - builds <FILE>.asm assembly file
#      build - builds and links all source files
#      all - same as build
#      compile-all - builds all target-dependent object files
#      clean - remove all generated files
#
# Platform Overrides:
#      PLATFORM - Plataforma destino (HOST o MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
ARCHM = armv7e-m
FLOAT = hard
FPU = fpv4-sp-d16
FLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -D$(PLATFORM)

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = $(FLAGS)
  LDFLAGS = -Wl,-Map=$(TARGET).map
else
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  LDFLAGS = -Wl,-Map=$(TARGET).map -T ../$(LINKER_FILE)
  CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall \
           -march=$(ARCHM) -mfloat-abi=$(FLOAT) \
           -mfpu=$(FPU) $(FLAGS)
endif
TARGET = c1m2

OBJS = $(SRCS:.c=.o)
OBJSI = $(SRCS:.c=.i)
OBJSS = $(SRCS:.c=.asm)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

$(TARGET).asm: $(TARGET).out
ifeq ($(PLATFORM),HOST)
	objdump --disassemble $< > $@
else
	arm-none-eabi-objdump --disassemble $< > $@
endif

%.asm : %.o
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@
ifeq ($(PLATFORM),HOST)
	objdump --disassemble $< > $@
else
	arm-none-eabi-objdump --disassemble $< > $@
endif

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@
ifeq ($(PLATFORM),HOST)
	size -Bx $(OBJS) $(TARGET).out
else
	arm-none-eabi-size -Bx $(OBJS) $(TARGET).out
endif

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJSI) $(OBJSS) $(TARGET).out $(TARGET).map $(TARGET).asm
