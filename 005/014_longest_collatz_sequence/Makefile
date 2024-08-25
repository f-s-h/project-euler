.PHONY: main, clean
CFLAGS= -O0 -std=c17 -lrt -Wall -Wextra

all: main debug

main: main.c
	$(CC) $(CFLAGS) -o $@ $^

debug: main.c
	$(CC) $(CFLAGS) -g -o debug $^

clean:
	rm -f main