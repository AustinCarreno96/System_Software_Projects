#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
int getByteWordValue(int directiveType, char* string) {
	char* buffer = (char*)malloc(sizeof(char) * strlen(string) + 1);
	char* final_buffer = (char*)malloc(sizeof(char) * strlen(string) + 1);
	char* end;

	if(directiveType == WORD) {
		return atoi(string);
	} else {
		if(string[0] == 'C') {
			for (int index = 2; index < strlen(string) - 1; index++) {
				sprintf(buffer, "%X", (int)(string[index]));
				strcat(final_buffer, buffer);
			}
			return strtol(final_buffer, &end, 16);
		} else if(string[0]== 'X') {
			for (int index = 2; index < strlen(string) - 1; index++) { final_buffer[index - 2] = string[index]; }
			return strtol(final_buffer, &end, 16);
		}
	}
	return 0;
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