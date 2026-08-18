CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = shellforge
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	gcc $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
