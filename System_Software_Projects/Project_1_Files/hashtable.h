#pragma once // Prevents the header file from loading multiple times

// Constants for the Student Structure
#define EMAIL_SIZE 18
#define NAME_SIZE 24
#define NUMBER_SIZE 10

// Constants for the Hash Table
#define HASH_TABLE_SEGMENTS 7 // Used in the hashing algorithm
#define MOD_SIZE 5 // Used in the hashing algorithm
#define NEW_LINE 10 // Newline character code
#define TABLE_SIZE 35 // Number of available spaces

int computerHash(char* studentName);
void displayHashTable(struct student* hashTable[]);
void displayRecord(struct student* temp, int index);
void initializeTable(struct student* hashTable[]);
void insertStudent(struct student* hashTable[], struct student* temp);
bool testEmailFormat(struct student temp);
bool testStudentData(struct student temp);

struct student {
	char name[NAME_SIZE];
	char number[NUMBER_SIZE];
	char email[EMAIL_SIZE];
	int credits;
	double gpa;
};

int computeHash(char* input) {
	int hash_value = 0;

    for(int index = 0; index < strlen(input); index++) {
        hash_value += input[index];
    }// end for loop

	return hash_value % MOD_SIZE * HASH_TABLE_SEGMENTS;
}// end computeHash()

void displayHashTable(struct student* hashTable[]) {
	
}// end displayHashTable()


void displayRecord(struct student* temp, int index) {

}// end displayRecord()


// initializing Table with NULL values
void initializeTable(struct student* hashTable[]) {
	for(int index = 0; index < TABLE_SIZE; index++) {
		hashTable[index] = NULL;
	}// end for loop

}// end initializeTable


void insertStudent(struct student* hashTable[], struct student* temp) {
	// Do not forget to use the malloc() function to reserve space for the student structure
	// Do not forget to use the strcpy() function to store the string data in the hash table

}// end insertStudent()


bool testEmailFormat(struct student temp) {

}// end testEmailFormat()


bool testStudentData(struct student temp) {
	
}// end testStudentData()