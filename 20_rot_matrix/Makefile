all: rotate-matrix

rotate.o: rotate.c
	gcc -c rotate.c

rotate-matrix: rotate.o
	gcc rotate.o read-matrix.o -o rotate-matrix
