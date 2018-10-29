default: prog

prog:
	gcc -Wall -std=c99 -o prog testme.c -coverage -fpic -lm
	./prog
		
clean:
	rm prog

cleanall: 
	rm prog 