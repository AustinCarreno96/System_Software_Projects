#include "headers.h"

#define INPUT_BUF_SIZE 60 // Size of the buffer used to read records from input file
#define	SEARCH_BUF_SIZE 25 // Size of the buffer used to read records from search file

struct student createStudent(char record[]);
void processInputFile(struct student* hashTable[], char* filename);
void processSearchFile(struct student* hashTable[], char* filename);
bool testRecord(char record[]);

int main(int argc, char *argv[]) {
	struct student hash_table[TABLE_SIZE];			// creating hash table with TABLE_SIZE
	initializeTable(hash_table);					// initalizing table with NULL values
	processInputFile(hash_table, "file_good.txt");	// begin processing file
}

struct student createStudent(char record[]) {
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// strcpy() - copies string data from one variable to another
	// strtol() - converts a string to its integer value
	// atof() 	- converts a string to its double value
	
	char* token = strtok(record, ",");		// separating the record by commas (delimiter)

}
 
void processInputFile(struct student* hashTable[], char* filename) {
	// Do not forget to use the following functions:
	// memset() - fill the buffer array with the specified character
	
	FILE *input;
	char* record = NULL;
	size_t length = 0;
	ssize_t read = 0;

	input = fopen(filename, "r");

	if(input == NULL) {
		perror("Error opening file :-(");
		exit(0);
	} else {
		while((read = getline(&record, &length, input)) != -1) {
			printf("> %s\n", record);								// TESTING
			
			struct student temp_student = createStudent(record);	// create student record and store it in a temp variable
			int key = computeHash(temp_student.name);				// Computing hash key value
			insertStudent(hashTable, &temp_student);
		}// end while()
	}// end if / else
}// end processInputFile()

void processSearchFile(struct student* hashTable[], char* filename) {
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// memset() - fill the buffer array with the specified character
}// end processSearchFile()

bool testRecord(char record[]) {

}// end testRecord()