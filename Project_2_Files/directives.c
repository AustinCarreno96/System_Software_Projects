#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};

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

int isDirective(char* string)  {
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

bool isStartDirective(int directiveType) {
	if (directiveType == START) {
		return true;
	} else { return false; }
}
