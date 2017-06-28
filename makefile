CFLAGS=-Wall -g

all: ex1 ex3 ex7 ex8

ex1: ex1.c
	gcc -o ex1 ex1.c

ex3: ex3.c
	gcc -o ex3 ex3.c

ex7: ex7.c
	gcc -o ex7 ex7.c

ex8: ex8.c
	gcc -o ex8 ex8.c

clean:
	rm -f ex1 ex3 ex7 ex8