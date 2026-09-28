CC = gcc
CFLAGS = -Wall -Wextra -std=c11

.PHONY: test clean

test: test_runner
	./test_runner

test_runner: list.c test.c list.h
	$(CC) $(CFLAGS) -o test_runner list.c test.c

clean:
	rm -f test_runner
