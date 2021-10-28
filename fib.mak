a: week4.o fib.o
	gcc week4.o fib.o
week4.o: week4.c
	gcc -c week4.c
fib.o: fib.c
	gcc -c fib.c