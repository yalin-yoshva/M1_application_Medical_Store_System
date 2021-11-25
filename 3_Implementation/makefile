# the compiler: gcc for C program, define as g++ for C++
CC = gcc
 
CFLAGS  = -g -Wall
 
# The build target 

BASEDIR = .
SRC_DIR = $(BASEDIR)/src
TEST_DIR = $(BASEDIR)/test
OBJ_DIR = $(BASEDIR)

TARGET = system
TEST_TARGET = systemTest
 
all:
		$(CC) $(CFLAGS) -o $(OBJ_DIR)/$(TARGET) $(SRC_DIR)/$(TARGET).c

clean:
		$(RM) $(BASEDIR)/$(TARGET) $(BASEDIR)/$(TEST_TARGET)

run: all
		./$(OBJ_DIR)/$(TARGET)

build_test:
		$(CC) $(CFLAGS) -o $(OBJ_DIR)/$(TEST_TARGET) $(TEST_DIR)/$(TEST_TARGET).c

test: all
		./$(OBJ_DIR)/$(TEST_TARGET)

