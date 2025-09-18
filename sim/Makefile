CC = gcc
CFLAGS = -Wall -g
TARGET = mcf_sim
SRC = main.c mcf8329a.c spi_mock.c

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
