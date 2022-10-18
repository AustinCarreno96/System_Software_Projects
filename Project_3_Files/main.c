#include <math.h>>
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
int hexToDecimal(struct segment* temp);

int main(int argc, char* argv[]) {
	address addresses = { 0x00, 0x00, 0x00 };
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
char* createFilename(char* filename, const char* extension) {
	char* temp = (char*)malloc(sizeof(char) * strlen(filename) + 1);
	
	strcpy(temp, filename);
	strcpy(temp, strtok(temp, "."));
	strcat(temp, extension);
	return temp;
}

void performPass1(struct symbol* symbolTable[], char* filename, address* addresses) {
	FILE *input;			// file pointer
	char* statement = NULL;	// each line in file
    size_t len = 0;
    ssize_t read = 0;
	struct segment* temp = { NULL };
	int decimal_value = 0;

	// Opening file
	input = fopen(filename, "r");

	// Checking to see if file is present
	printf("%p", input);
	if(input == NULL) {
		displayError(FILE_NOT_FOUND, filename);
		exit(0);
	} else {
        printf("\n\nSymbol Table Log\n");
        printf("----------------\n");

        while((read = getline(&statement, &len, input)) != -1) {		
			
			addresses->current += addresses->increment;	// incrementing current address
			
			// Testing PC address value
			if(addresses->current > 32768) {
				char error_info[100];		// Arbitrary number. Need to figure out a better solution for string size
				sprintf(error_info, "0x%X", addresses->current);
				displayError(7, error_info);
				exit(0);
			}

			// testing for blank record
			if(statement[0] < 32) {
				displayError(1, ""); 
				exit(0);
			} else if(statement[0] == 35) { continue; }	// Checking for comments

		
			// preparing segments
			temp = prepareSegments(statement);
// ------------------------------------------------------------------------------------------------------------------------------------------------			
			// Testing first segment
			int first_segment_directive = isDirective(temp->first);
			bool first_segment_opcode = isOpcode(temp->first);
			
			if(first_segment_directive != 0 || first_segment_opcode == true) {
				displayError(5, temp->first);
				exit(0);
			}
// ------------------------------------------------------------------------------------------------------------------------------------------------			

			// testing if the second segment is a directive
			int second_segment = isDirective(temp->second);

			if(second_segment != 0) {
				if(second_segment == 6) {
					if(atoi(temp->third) > 16777215 || atoi(temp->third) < -16777216) {
						displayError(9, temp->third);
						exit(0);
					}
				}
				// Starting address indexing
				if(isStartDirective(second_segment)) {
					// addresses->start = atoi(temp->third);
					addresses->current = hexToDecimal(temp);
					addresses->start = hexToDecimal(temp);
					continue;
				} else {
					// Getting the increment value for memory address
					addresses->increment = getMemoryAmount(second_segment, temp->third);
				}
			} else {  
				if(isOpcode(temp->second)) {
					addresses->increment = 3;
				} else {
					displayError(4, temp->second);
					exit(0);
				}
			 }	// Go to next line if there is an error
// ------------------------------------------------------------------------------------------------------------------------------------------------
            if(temp->first[0] != '\0') { insertSymbol(symbolTable, temp->first, addresses->current); }


			memset(statement, 0, INPUT_BUF_SIZE);		// resetting memory at the record array for new record
        } // end while loop
	}// end if / else

    fclose(input);
	return;
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void performPass2(struct symbol* symbolTable[], char* filename, address* addresses)
{
	// Do not modify this statement
	objectFileData objectData = { 0, { 0x0 }, { "\0" }, 0, 0x0, 0, { 0 }, 0, '\0', 0x0 };

	// Your code should start here
}

segment* prepareSegments(char* statement) {
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
void resetObjectFileData(objectFileData* objectData, address* addresses) {
	
}

// To implement Pass 2 of the assembler for Project 3,
// Use the following function to replace the function
// In your existing Project 2 code
void trim(char value[]) {
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
void writeToLstFile(FILE* file, int address, segment* segments, int opcode) {
	
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
void writeToObjFile(FILE* file, objectFileData fileData) {
	
}


int hexToDecimal(struct segment* temp) {
	int decimal_value = 0;
    int index = 0;
	int val = 0;
  
    int length = strlen(temp->third) - 1;
  
    while (temp->third[index] != '\0') {
  
		// finding the equivalent decimal digit for each hexadecimal digit
        if (temp->third[index] >= '0' && temp->third[index] <= '9') { val = temp->third[index] - 48; } 
		else if (temp->third[index] >= 'a' && temp->third[index] <= 'f') { val = temp->third[index] - 97 + 10; } 
		else if (temp->third[index] >= 'A' && temp->third[index] <= 'F') { val = temp->third[index] - 65 + 10; }
        
        decimal_value += val * pow(16, length);
        length--;
        index++;
    }

	return decimal_value;
}