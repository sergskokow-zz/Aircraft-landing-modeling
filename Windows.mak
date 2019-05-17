CC = gcc
CFLAGS = -Wall -O3
DEPENDENCIES = cJSON/cJSON.c
SOURCES = $(wildcard *.c) $(DEPENDENCIES)
TARGET = build/Task2

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	del /Q $(TARGET)
