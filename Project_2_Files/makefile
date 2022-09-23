

directives.o: directives.c
	gcc -c directives.c

errors.o: errors.c
	gcc -c errors.c

opcodes.o: opcodes.c
	gcc -c opcodes.c

symbols.o: symbols.c
	gcc -c symbols.c

main.o: main.c
	gcc -c main.c ./test0.sic

symbolTable: directives.o errors.o opcodes.o symbols.o main.o
	gcc directives.o errors.o opcodes.o symbols.o main.o -o symbolTable
clean:
	rm *.o symbolTable
