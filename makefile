CFLAGS=-Wall -g

all: ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16

ex1: ex1.c
	gcc -o ex1 ex1.c

ex3: ex3.c
	gcc -o ex3 ex3.c

ex7: ex7.c
	gcc -o ex7 ex7.c

ex8: ex8.c
	gcc -o ex8 ex8.c

ex9: ex9.c
	gcc -o ex9 ex9.c

ex10: ex10.c
	gcc -o ex10 ex10.c

ex11: ex11.c
	gcc -o ex11 ex11.c

ex12: ex12.c
	gcc -o ex12 ex12.c

ex13: ex13.c
	gcc -o ex13 ex13.c

ex14: ex14.c
	gcc -o ex14 ex14.c

ex15: ex15.c
	gcc -o ex15 ex15.c

ex16: ex16.c
	gcc -o ex16 ex16.c


clean:
	rm -f ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16
