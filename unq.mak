a: unique.o week4.o
	gcc unique.o week4.o
week4.o: week4.c unique.h
	gcc -c week4.c unique.h
unique.o: unique.c
	gcc -c unique.c