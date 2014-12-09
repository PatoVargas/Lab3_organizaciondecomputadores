# makefile para las funciones 

all : f1e f2e f3e f4e f1v f2v
.PHONY : all

f1e : funcion1escalar.o 
	cc -o f1e funcion1escalar.o -lm

f2e : funcion2escalar.o
	cc -o f2e funcion2escalar.o -lm

f3e : funcion3escalar.o
	cc -o f3e funcion3escalar.o -lm

f4e : funcion4escalar.o
	cc -o f4e funcion4escalar.o -lm

f1v : funcion1vectorial.o
	cc -o f1v funcion1vectorial.o 

f2v : funcion2vectorial.o
	cc -o f2v funcion2vectorial.o 

funcion1escalar.o : funcion1escalar.c 
		cc -c funcion1escalar.c

funcion2escalar.o : funcion2escalar.c 
		cc -c funcion2escalar.c

funcion3escalar.o : funcion3escalar.c 
		cc -c funcion3escalar.c

funcion4escalar.o : funcion4escalar.c 
		cc -c funcion4escalar.c

funcion1vectorial.o : funcion1vectorial.c 
		cc -std=gnu99  -c funcion1vectorial.c -msse -msse2 -msse3

funcion2vectorial.o : funcion2vectorial.c 
		cc -std=gnu99  -c funcion2vectorial.c -msse -msse2 -msse3

clean: 
	rm f1e f2e f3e f4e f1v f2v funcion1escalar.o funcion2escalar.o \
	funcion3escalar.o funcion4escalar.o funcion1vectorial.o funcion2vectorial.o
