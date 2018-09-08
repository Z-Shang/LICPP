CC=g++-8
CFLAGS=-std=c++17 -Wall -Wextra

tests:
	$(CC) $(CFLAGS) tests.cpp -o tests
