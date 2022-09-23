symbolTable: directives.o errors.o opcodes.o symbols.o main.o
	gcc directives.o errors.o opcodes.o symbols.o main.o -o symbolTable

directives.o: directives.c
	gcc -c directives.c -o directives.o

errors.o: errors.c
	gcc -c errors.c -o errors.o

opcodes.o: opcodes.c
	gcc -c opcodes.c -o opcodes.o

symbols.o: symbols.c
	gcc -c symbols.c -o symbols.o

main.o: main.c
	gcc -c main.c ./test0.sic -o main.o -include headers.h

clean:
	rm *.o symbolTable
