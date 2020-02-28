program: main.o lab3.o
	gcc -o program main.o lab3.o

main.o: main.c lab3.h
	gcc -c main.c
	
lab3.o: lab3.c lab3.h
	gcc -c lab3.c
	
clean:
	rm -f *.o program