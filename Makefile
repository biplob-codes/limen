CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -g

program: *.c
	$(CC) $(CFLAGS) *.c -o program

run: program
	./program

clean:
	rm -f program