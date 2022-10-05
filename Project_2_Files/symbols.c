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
    printf("\n\n\nSymbol Table Contents\n");
	printf("---------------------\n\n");

	printf("=======================================================================\n");
	printf("\tIndex\t\t\tName\t\t\tAddress\n");
	printf("=======================================================================\n");
	for(int index = 0; index < SYMBOL_TABLE_SIZE; index++) {
		if(symbolTable[index] != NULL) {
            printf("%11d\t\t\t%-23s 0x%X\n", index, symbolTable[index]->name, symbolTable[index]->address);
		} else { continue; }
	}// end for loop
    printf("\n\n");
    return;
}

void initializeSymbolTable(struct symbol* symbolTable[]) { }

void insertSymbol(struct symbol* symbolTable[], char symbolName[], int symbolAddress) {
    int key = computeHash(symbolName);                      // computing hash
    struct symbol final = {.name = "", .address = 0};       // creating symbol struct


    // checking for duplicates and ensuring index in key is open
    while(symbolTable[key] != NULL) {
        if(strcmp(symbolName, symbolTable[key]->name) == 0) { 
			displayError(2, symbolName);
            exit(0);
		} else { 
			key += 1; 
			if(key == (SYMBOL_TABLE_SIZE - 1)) {
				key = 0;
			} 
		}// end if / else  
    }// end while loop

    strcpy(final.name, symbolName);     // getting symbol name
    final.address = symbolAddress;      // getting symbol address

    struct symbol* final_ptr = &final;  // creating pointer to symbol struct for table
    
    symbolTable[key] = (struct symbol*) malloc(sizeof(struct symbol));
    *(symbolTable[key]) = *final_ptr;
    printf("Added %s to Symbol Table at Index %-5d\n", symbolTable[key]->name, key);
    return;
}