project2: main.o project2.o
		gcc -o project2 main.o project2.o
		
main.o: main.c project2.h
		gcc -c main.c
		
project2.o: project2.c project2.h
		gcc -c project2.c
		
clean: 
		rm -f *.o project2