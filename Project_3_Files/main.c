#include "headers.h"

#define COMMENT 35
#define INDEX_STRING ",X"
#define INPUT_BUF_SIZE 60
#define NEW_LINE 10
#define SPACE 32
#define SYMBOL_TABLE_SIZE 100

// Pass 2 constants
#define BLANK_INSTRUCTION 0x000000
#define OPCODE_MULTIPLIER 0x10000
#define OUTPUT_BUF_SIZE 70
#define RSUB_INSTRUCTION 0x4C0000
#define X_MULTIPLER 0x8000


void performPass1(struct symbol* symbolArray[], char* filename, address* addresses);
struct segment* prepareSegments(char* line);
void trim(char string[]);

// Pass 2 function prototypes
char* createFilename(char* filename, const char* extension);
void performPass2(struct symbol* symbolTable[], char* filename, address* addresses);
void resetObjectFileData(objectFileData* objectData, address* addresses);
void writeToLstFile(FILE* file, int address, segment* segments, int opcode);
void writeToObjFile(FILE* file, objectFileData data);

int main(int argc, char* argv[])
{
	address addresses = { 0x00, 0x00, 0x00 };
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
char* createFilename(char* filename, const char* extension)
{
	char* temp = (char*)malloc(sizeof(char) * strlen(filename) + 1);
	
	strcpy(temp, filename);
	strcpy(temp, strtok(temp, "."));
	strcat(temp, extension);
	return temp;
}

void performPass1(struct symbol* symbolTable[], char* filename, address* addresses)
{
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void performPass2(struct symbol* symbolTable[], char* filename, address* addresses)
{
	// Do not modify this statement
	objectFileData objectData = { 0, { 0x0 }, { "\0" }, 0, 0x0, 0, { 0 }, 0, '\0', 0x0 };

	// Your code should start here
}

segment* prepareSegments(char* statement)
{
	struct segment* temp = (segment*)malloc(sizeof(segment));
	strncpy(temp->first, statement, SEGMENT_SIZE - 1);
	strncpy(temp->second, statement + SEGMENT_SIZE - 1, SEGMENT_SIZE - 1);
	strncpy(temp->third, statement + (SEGMENT_SIZE - 1) * 2, SEGMENT_SIZE - 1);

	trim(temp->first);
	trim(temp->second);
	trim(temp->third);
	return temp;
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void resetObjectFileData(objectFileData* objectData, address* addresses)
{
	
}

// To implement Pass 2 of the assembler for Project 3,
// Use the following function to replace the function
// In your existing Project 2 code
void trim(char value[])
{
	for (int x = 0; x < SEGMENT_SIZE; x++)
	{
		if (value[x] == SPACE || x == (SEGMENT_SIZE - 1))
		{
			value[x] = '\0';
		}
	}
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void writeToLstFile(FILE* file, int address, segment* segments, int opcode)
{
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void writeToObjFile(FILE* file, objectFileData fileData)
{
	
}