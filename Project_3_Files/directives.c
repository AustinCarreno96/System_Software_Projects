#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
int getByteWordValue(int directiveType, char* string)
{
	
}

int getMemoryAmount(int directiveType, char* string)
{
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isDataDirective(int directiveType)
{
	
}

int isDirective(char* string) {

}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isEndDirective(int directiveType)
{
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
bool isReserveDirective(int directiveType)
{
	
}

bool isStartDirective(int directiveType)
{
	
}