.PHONY: main, clean
CFLAGS= -O0 -std=c17 -lrt -Wall -Wextra

all: main

main: main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f main