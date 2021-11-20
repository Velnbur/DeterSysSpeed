##
# lab1
#
# @file
# @version 0.1

# result funcs int char longlong float double build

CC=gcc
CCFLAGS=-Wall -g -O0

SRC_PATH=src
BUILD_PATH=$(SRC_PATH)/build
LIB_PATH=$(SRC_PATH)/lib
BIN_PATH=$(SRC_PATH)/bin

PROJECT_NAME=lab1

#find all *.c files in src/lib dirs and add .o suffix to them
LIB_MODULES=$(addsuffix .o, $(basename $(wildcard $(LIB_PATH)/*/*.c))) 

all: dirs build

dirs:
	@mkdir -p $(BIN_PATH) $(BUILD_PATH)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $< -o $(BUILD_PATH)/$(notdir $@)

build: $(LIB_MODULES)
	$(CC) $(CCFLAGS) $(SRC_PATH)/main.c $(addprefix $(BUILD_PATH)/, $(notdir $^)) -o $(BIN_PATH)/$(PROJECT_NAME)


