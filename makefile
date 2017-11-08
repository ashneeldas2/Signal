all: signal.c
	gcc -o signal signal.c

run: signal
	./signal
