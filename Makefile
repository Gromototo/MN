all: test_abr

abr.o: abr.c abr.h pile.h file.h
	gcc -Wall -c abr.c

pile.o: pile.h pile.c abr.h
	gcc -Wall -c pile.c

file.o: file.h file.c
	gcc -Wall -c file.c

test_abr.o: test_abr.c abr.h
	gcc -Wall -c test_abr.c

test_abr: test_abr.o pile.o file.o abr.o
	gcc -o test_abr abr.o pile.o file.o test_abr.o

clean:
	rm -f *.o *~ test_abr


pile_test.o: pile_test.c pile.c pile.h
	gcc -Wall -c pile_test.c

pile_test: pile_test.o abr.o pile.o file.o
	gcc -o pile_test pile_test.o abr.o pile.o file.o

file_test.o: file_test.c file.c file.h
	gcc -Wall -c file_test.c

