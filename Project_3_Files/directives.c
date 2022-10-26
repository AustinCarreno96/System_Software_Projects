#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
int getByteWordValue(int directiveType, char* string) {
	int end_index = strlen(string) - 1;		// Getting last index of string
	char* buffer;
	char* final_buffer;

	if (string[0] == 'C') {
		// // Grabbing values inside quotations
		// for(int index = 0; index <= end_index; index++) {
		// 	sprintf(buffer, "%s", string);
		// 	// strcat(final_buffer, buffer);
		// }	
	} 
	// else if (string[0] == 'X') {
	// 	printf("%s", final_buffer);
	// 	return atoi(final_buffer);
	// }

	return 0;//TODO: Return Value
}

int getMemoryAmount(int directiveType, char* string) {
	int memory_amount = 0;

	switch(directiveType) {
		case START:
		case END:
			break;
		case BYTE:
			if(string[0] == 'X') {
				memory_amount = 1;
			} else {
				memory_amount = strlen(string) - 3;
			}
			break;
		case RESW:
			memory_amount = 3 * atoi(string);
			break;
		case RESB:
			memory_amount = atoi(string);
			break;
		case WORD:
			memory_amount = 3;
			break;
		default:
			memory_amount = 3;
			break;
	}
	return memory_amount;
}


// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isDataDirective(int directiveType) {
	if (directiveType == BYTE || directiveType == WORD) {
		return true;
	} else { return false; }
}

int isDirective(char* string) {
	int directiveType = 0;
	if (strcmp(string, "BYTE") == 0) {
		return BYTE;
	} else if (strcmp(string, "END") == 0) { 
		return END;
	} else if (strcmp(string, "RESB") == 0) {
		return RESB;
	} else if (strcmp(string, "RESW") == 0) {
		return RESW;
	} else if (strcmp(string, "START") == 0) { 
		return START;
	} else if (strcmp(string, "WORD") == 0) { 
		return WORD;
	} else { return ERROR; } 
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isEndDirective(int directiveType) {
	if (directiveType == END) {
		return true;
	} else { return false; }
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isReserveDirective(int directiveType) {
	if (directiveType == RESW || directiveType == RESB) {
		return true;
	} else { return false; }
}

bool isStartDirective(int directiveType) {
	if (directiveType == START) {
		return true;
	} else { return false; }
}