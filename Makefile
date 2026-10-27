CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

test: vector.c test_vector.c vector.h
	$(CC) $(CFLAGS) vector.c test_vector.c -o test
	./test

clean:
	rm -rf test test.dSYM

.PHONY: test clean