#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for host as well as MSP432 build system.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      
#      <FILE>.i - Builds <File>.i preprocessed file
#      <FILE>.asm - Generates <File>.asm assembly file
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      compile-all - Compiles all object files, does not link
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM - (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk


# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
STANDARD = c99

# Compiler Flags and Defines

TARGET = course1
LDFLAGS = -Wl,-Map=$(TARGET).map

ifeq ($(PLATFORM),HOST)
	CC = gcc
	# Adding compiler for host platform
	LD = ld
	# Adding compiler for host platform
	OBJDUMP_TOOL = objdump
	# Adding compiler for host platform
else
	CC = arm-none-eabi-gcc
	#Defining compiler for MSP432 platform
	LD = arm-none-eabi-ld
	#Defining compiler for MSP432 platform
	LDFLAGS += -T $(LINKER_FILE)
	#Defining linker for MSP432 platform
	OBJDUMP_TOOL = arm-none-eabi-objdump
	#Defining compiler for MSP432 platform
endif 
 
CFLAGS = -Wall \
	-Werror \
	-g \
	-O0 \
	-std=$(STANDARD) \
	-D$(PLATFORM) \
	-DCOURSE1 
ifeq ($(PLATFORM),MSP432)
CFLAGS += --specs=$(SPECS) \
	-mcpu=$(CPU) \
	-march=$(ARCH) \
	-mthumb \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16
	#architecture specific flags for MSP432 platform
endif 


# Printing Enable

ifeq ($(PRINT),VERBOSE)
CFLAGS += -DVERBOSE
endif

CPPFLAGS = -MD

SRCDIR := src
OBJDIR := output

SRCFILES = $(SOURCES) 
OBJFILES := $(patsubst $(SRCDIR)/%.c, %.o,$(SRCFILES))


#%.i : $(SOURCES)
#	$(CC) $(INCLUDES) $(CFLAGS) $< -E -o $@  
#
#$(TARGET).asm: compile-all
#	$(CC) $(CFLAGS) $(OBJS) -o c1m2.out
#	$(OBJDUMP_TOOL) -S c1m2.out > c1m2.asm
#
#%.asm : $(SOURCES)
#	$(CC) $(INCLUDES) $(CFLAGS) $< -S -o $@
#
#%.o : $(SOURCES)
#	$(CC) $(INCLUDES) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	rm -f $(TARGET).out *.map *.o *.asm *.i *.d

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) -c 
	
.PHONY: build
build: $(SRCFILES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SRCFILES) $(CPPFLAGS) -c  
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET).out $(LDFLAGS)
	size -Bd $(TARGET).out



