CC = gcc
CFLAGS = -Wall -Wextra

all: stack.exe

stack.exe: main.o t_stack.o
	$(CC) $(CFLAGS) -o stack.exe main.o t_stack.o

main.o: main.c t_stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

t_stack.o: t_stack.c t_stack.h
	$(CC) $(CFLAGS) -c -o t_stack.o t_stack.c

clean:
	rm -f stack.exe main.o t_stack.o
