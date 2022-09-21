#include "headers.h"

#define MOD_SIZE 10
#define SYMBOL_TABLE_SEGMENTS 10
#define SYMBOL_TABLE_SIZE 100

int computeHash(char* input);

int computeHash(char* symbolName) {
    int hash_value = 0;

    for(int index = 0; index < strlen(symbolName); index++) { hash_value += symbolName[index]; }// end for loop

	return hash_value % SYMBOL_TABLE_SIZE;
}

void displaySymbolTable(struct symbol* symbolTable[]) {

}

void initializeSymbolTable(struct symbol* symbolTable[]) {

}

void insertSymbol(struct symbol* symbolTable[], char symbolName[], int symbolAddress) {

}