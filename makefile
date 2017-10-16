CFLAGS+=-Wall -g
# set dynamic database size for exercise 17 based on user input for
# make file otherwise define default constants

# TODO alert user that default values are being used and inform
# them how to set dynamic database size if they desire
DEFAULT_MAX_ROWS = -DMAX_ROWS=100
DEFAULT_MAX_DATA = -DMAX_DATA=512
ifeq ($(MAX_ROWS),)
	MAX_ROWS := $(DEFAULT_MAX_ROWS)
endif
ifeq ($(MAX_DATA),)
	MAX_DATA := $(DEFAULT_MAX_DATA) 
endif

all: 	ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 \
			ex13 ex14 ex15 ex16 ex17 ex18

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


# DYNAMICALLY SET ROWS AND DATA ALLOWED AT COMPILATION
ex17: ex17.c
	gcc $(MAX_ROWS) $(MAX_DATA) -o ex17 ex17.c

ex18: ex18.c
	gcc -o ex18 ex18.c

clean:
	rm -f ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 \
				ex13 ex14 ex15 ex16 ex17 ex18
