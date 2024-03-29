# Makefile for cnn-cifar10 project

# CC = gcc
# CFLAGS = -Wall -Wextra -std=c11
CC = nvc
CFLAGS = -g -Minfo=all -c11 -Wall -Wextra -march=native

SRC = main.c
EXECUTABLE = cnn-cifar10

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(EXECUTABLE)
