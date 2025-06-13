CC = gcc
CFLAGS = -Wall -Wextra

all: test

build:
	$(CC) $(CFLAGS) -o gestione_studio main.c attivita.c

test_runner: test_runner.c
	$(CC) $(CFLAGS) -o test_runner test_runner.c

test: build test_runner
	./test_runner

clean:
	rm -f gestione_studio test_runner output.txt