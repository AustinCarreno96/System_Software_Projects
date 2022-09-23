#include "headers.h"

#define COMMENT 35
#define INPUT_BUF_SIZE 60
#define NEW_LINE 10
#define SPACE 32
#define SYMBOL_TABLE_SIZE 100

void performPass1(struct symbol* symbolArray[], char* filename, address* addresses);
struct segment* prepareSegments(char* line);
void trim(char string[]);

int main(int argc, char* argv[]) {
	// Do not modify this statement
	struct address addresses = { 0x00, 0x00, 0x00 };

	// Your code should start here
	// Checking if all command line args have been passed
	// if (argc < 2) {
	// 	displayError(E_MISSING_COMMAND, " ");
	// }
	printf("TESTESTESTESTTEST");
	struct symbol* symbolTable[SYMBOL_TABLE_SIZE] = { NULL };		// Initializing table here.
	performPass1(symbolTable, argv[1], &addresses);
}

void performPass1(struct symbol* symbolTable[], char* filename, address* addresses) {
	FILE *input;			// file pointer
	char* statement = NULL;	// each line in file
    size_t len = 0;
    ssize_t read = 0;

	// Opening file
	input = fopen(filename, "r");

	// Checking to see if file is present
	if(input == NULL) {
		displayError(FILE_NOT_FOUND, filename);
	} else {
        printf("\n\nSymbol Table Log\n");
        printf("--------------\n");

        while((read = getline(&statement, &len, input)) != -1) {			
			struct segment* temp = prepareSegments(statement);
			if(strcmp(temp->first, "#") == 0) { continue; }

			if(strcmp(temp->second, "START") == 0) {printf("TEST");}


            memset(statement, 0, INPUT_BUF_SIZE);		// resetting memory at the record array for new record
        
        } // end while loop
	}// end if / else
    fclose(input);
}

// Do no modify any part of this function
segment* prepareSegments(char* statement) {
	struct segment* temp = malloc(sizeof(segment));
	strncpy(temp->first, statement, SEGMENT_SIZE - 1);
	strncpy(temp->second, statement + SEGMENT_SIZE - 1, SEGMENT_SIZE - 1);
	strncpy(temp->third, statement + (SEGMENT_SIZE - 1) * 2, SEGMENT_SIZE - 1);

	trim(temp->first);
	trim(temp->second);
	trim(temp->third);
	return temp;
}

// Do no modify any part of this function
void trim(char value[]) {
	for (int x = 0; x < SEGMENT_SIZE; x++) {
		if (value[x] == SPACE) {
			value[x] = '\0';
		}
	}
}