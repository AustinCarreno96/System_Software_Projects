#include <math.h>
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
void removeChar(char* string, char removed_char);

void printlstFile(address* addresses, struct segment* seg, int value);

// TODO: I have added all steps from project_3 todo list. I now need to go back and check on memory after each iteration of 
//		 of the while loop. 


int main(int argc, char* argv[]) {
	address addresses = { 0x00, 0x00, 0x00 };
	
	// Checking if all command line args have been passed
	if (argc < 2) {
		displayError(MISSING_COMMAND_LINE_ARGUMENTS, " ");
		exit(0);
	}
	
	struct symbol* symbolTable[SYMBOL_TABLE_SIZE] = { NULL };		// Initializing table here.
	performPass1(symbolTable, argv[1], &addresses);
	performPass2(symbolTable, argv[1], &addresses);
}

// To implement Pass 2 of the assembler for Project 3,
// Add the following function to your existing Project 2 code
char* createFilename(char* filename, const char* extension) {
	char* temp = (char*)malloc(sizeof(char) * strlen(filename) + 1);
    char* temp1 = (char*)malloc(sizeof(char) * strlen(filename) + 1);
	strcpy(temp1, filename);
	strcpy(temp, strtok(temp1, "."));
	// exit(0);
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
	if(input == NULL) {
		displayError(FILE_NOT_FOUND, filename);
		exit(0);
	} else {
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
void performPass2(struct symbol* symbolTable[], char* filename, address* addresses) {
	// Do not modify this statement
	objectFileData objectData = { 0, { 0x0 }, { "\0" }, 0, 0x0, 0, { 0 }, 0, '\0', 0x0 };

	// Your code should start here

	// FILE pointers for all files needed to be opened / written in / etc.
	FILE *input;
	FILE *lst_output;
	FILE *obj_output;

	char* statement = NULL;	// each line in file
    
	size_t len = 0;
    ssize_t read = 0;
	
	// Initializing segments
	struct segment* temp_segment = { NULL };
	
	// TODO: Not sure if these will be needed?
	char h_record[19];
	char t_record[69];
	char e_record[7];
	
	// For later use
	int decimal_value = 0;
	int diff = 0;
	
	// Creating lst and obj file names
	char* lst_file = createFilename(filename, ".lst");
	char* obj_file = createFilename(filename, ".obj");

	// Opening sic file
	input = fopen(filename, "r");

	if(input == NULL) {
		displayError(FILE_NOT_FOUND, filename);
		exit(0);
	} else {
		// Opening lst and obj files
		lst_output = fopen(lst_file, "w");
		// obj_output = fopen(obj_file, "w");

		while((read = getline(&statement, &len, input)) != -1) {
			if(statement[0] == 35) { continue; }	// Checking for comments
			
			temp_segment = prepareSegments(statement);	
			
			// TODO: Find a way to get rid of
			int second_segment_directive = isDirective(temp_segment->second);
			
			if(isDirective(temp_segment->second) > 0) {
					// Starting address indexing
					if(isStartDirective(second_segment_directive)) {
						objectData.recordType = 'H';
						strcpy(objectData.programName, temp_segment->first);
						objectData.startAddress = addresses->start;
						objectData.recordAddress = addresses->start;
						objectData.programSize = addresses->current - addresses->start;

						addresses->current = addresses->start;

						writeToObjFile(obj_output, objectData);

						// TODO: Testing
						writeToLstFile(lst_output, addresses->start, temp_segment, BLANK_INSTRUCTION);

						// addresses->current = hexToDecimal(temp);
						// addresses->start = hexToDecimal(temp);
						continue;
					} else if(isEndDirective(second_segment_directive)) {
						if(objectData.recordByteCount > 0) {
							writeToObjFile(obj_output, objectData);

							// TODO: Testing
							resetObjectFileData(&objectData, addresses);
						}

						objectData.recordType = 'E';

						writeToObjFile(obj_output, objectData);

						// TODO: Testing
						writeToLstFile(lst_output, addresses->start, temp_segment, BLANK_INSTRUCTION);
					} else if(isReserveDirective(second_segment_directive)) {
						if(objectData.recordByteCount > 0) {
							writeToObjFile(obj_output, objectData);

							// TODO: Testing
							resetObjectFileData(&objectData, addresses);
						}

						// TODO: Testing
						writeToLstFile(lst_output, addresses->start, temp_segment, BLANK_INSTRUCTION);
						addresses->increment = getMemoryAmount(second_segment_directive, temp_segment->third);
						objectData.recordAddress = addresses->increment;
					} else if(isDataDirective(second_segment_directive)) {
						addresses->increment = getMemoryAmount(second_segment_directive, temp_segment->third);
						diff = MAX_RECORD_BYTE_COUNT - addresses->increment;

						if(objectData.recordByteCount > 0) {
							writeToObjFile(obj_output, objectData);
							resetObjectFileData(&objectData, addresses);
						}
						char* temp_third_seg = temp_segment->third;
						removeChar(temp_third_seg, '\'');
						removeChar(temp_third_seg, '\'');

						// TODO: Commented out code causing segmentation fault
						int value = getByteWordValue(second_segment_directive, temp_segment->third);
						objectData.recordEntries->numBytes = addresses->increment;
						objectData.recordEntries->value = value;

						objectData.recordEntryCount++;
						objectData.recordByteCount += addresses->increment;

						// writeToLstFile(lst_output, addresses->start, temp_segment, getByteWordValue(second_segment_directive, temp_segment->third));
					}
				// }
			} else if(isOpcode(temp_segment->second)) {
				diff = MAX_RECORD_BYTE_COUNT - 3;

				// TODO: Test0.sic never reaching this if. Always going to else statement
				if(objectData.recordByteCount > diff) {
					writeToObjFile(obj_output, objectData);
					resetObjectFileData(&objectData, addresses);
				}
					
				int opcode_value = getOpcodeValue(temp_segment->second);
				opcode_value *= OPCODE_MULTIPLIER;
				
				// printf("Opcode: %s\tValue: %X\n",temp_segment->second, opcode_value);
				
				if(strstr(temp_segment->third, ",X")) {
					opcode_value += X_MULTIPLER;				// Getting new opcode value with X_MULTIPLIER
					removeChar(temp_segment->third, ',');			// Removing the ',' and 'X' from third segment
					removeChar(temp_segment->third, 'X');
					opcode_value += getSymbolAddress(symbolTable, temp_segment->third);		// Adding symbol Address to opcode value
				}

				if(getOpcodeValue(temp_segment->second) != 0x4C) {
					// Testing for third segment in symbol table
					int addr = getSymbolAddress(symbolTable, temp_segment->third);
					if(addr == -1) {
						// displayError(UNDEFINED_SYMBOL, "");
						// exit(0);
					}
					
					opcode_value += addr;
					objectData.recordEntries->numBytes = 3;
					objectData.recordEntries->value = opcode_value;
					objectData.recordEntryCount += 1;
					objectData.recordByteCount += 3;

					writeToLstFile(lst_output, addresses->start, temp_segment, opcode_value);
					addresses->increment = 3;
				}
			}
			printlstFile(addresses, temp_segment, objectData.recordEntries->value);
			addresses->current += addresses->increment;		// Increment current address
		}// end while
	}// end if / else

	fclose(lst_output);
	fclose(obj_output);
}// end performPass2()

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
	objectData->recordAddress = addresses->current;
	objectData->recordByteCount = 0;
	objectData->recordEntryCount = 0;
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
	// fprintf(file, "%s", fileData.recordType);
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

void removeChar(char* string, char removed_char) {
    int i, j;
    i = 0;
    while(i<strlen(string)) {
        if (string[i] == removed_char) { 
            for (j = i; j<strlen(string); j++) { string[j]=string[j+1]; }
        } else { i++; }
    }// end while
}// end removeChar()


//TODO: Testing
void printlstFile(address* addresses, struct segment* seg, int value) {
	if (value > 0) {
		printf("%X\t%s\t%s\t%s\t%X\n", addresses->current, seg->first, seg->second, seg->third, value);
	} else { printf("%X\t%s\t%s\t%s\n", addresses->current, seg->first, seg->second, seg->third); }
	
}