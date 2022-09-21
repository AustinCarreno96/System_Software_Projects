#include <regex.h>

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

struct student {
	char name[NAME_SIZE];
	char number[NUMBER_SIZE];
	char email[EMAIL_SIZE];
	int credits;
	double gpa;
};


int computerHash(char* studentName);
void displayHashTable(struct student* hashTable[]);
void displayRecord(struct student* temp, int index);
void initializeTable(struct student* hashTable[]);
void insertStudent(struct student* hashTable[], struct student* temp);
bool testEmailFormat(struct student temp);
bool testStudentData(struct student temp);



int computeHash(char* input) {
	int hash_value = 0;

    for(int index = 0; index < strlen(input); index++) {
        hash_value += input[index];
    }// end for loop

	return hash_value % TABLE_SIZE;
}// end computeHash()


void displayHashTable(struct student* hashTable[]) {
	printf("\n\n\nHash Table Contents\n");
	printf("-------------------\n\n");

	printf("====================================================================================================================================\n");
	printf("\tIndex\t\t\tName\t\t\tNumber\t\t\tEmail\t\t\tCredits\t\t\tGPA\n");
	printf("====================================================================================================================================\n");
	for(int index = 0; index < TABLE_SIZE; index++) {
		if(hashTable[index] != NULL) {
			displayRecord(hashTable[index], index);
		} else { continue; }
	}
}// end displayHashTable()


void displayRecord(struct student* temp, int index) {
	printf("%10d %30s %21s %29s %15d %22.1lf\n\n", index, 
												   temp->name,
												   temp->number,
												   temp->email,
												   temp->credits,
												   temp->gpa);
}// end displayRecord()


// initializing Table with NULL values
void initializeTable(struct student* hashTable[]) { }// end initializeTable


void insertStudent(struct student* hashTable[], struct student* temp) {
	// Do not forget to use the malloc() function to reserve space for the student structure
	// Do not forget to use the strcpy() function to store the string data in the hash table

	int key = computeHash(temp->name);	// computing hash key
	int original_key = key;
	while(hashTable[key] != NULL) {
		if(temp->name == hashTable[key]->name) { 
			displayError(E_DUPLICATE_NAME, temp->name);
		} else { 
			key += 1; 
			if(key == (TABLE_SIZE - 1)) {
				key = 0;
			} 
		}// end if / else
	}// end while loop

	hashTable[key] = (struct student*) malloc(sizeof(struct student));	// allocating memory in hashtable where the key is

	*(hashTable[key]) = *temp;
	printf("Added Student to Hash Table: %-30s Target: %-5d  Actual: %d\n", hashTable[key]->name,
																		   original_key,
																		   key);
	return;	
}// end insertStudent()


bool testEmailFormat(struct student temp) {
	regex_t reg;
	int return_value;

	return_value = regcomp(&reg, "^u[0-9]{8}@ufb\\.edu$", REG_EXTENDED | REG_ICASE);
	return_value = regexec(&reg, temp.email, 0, NULL, 0);
	
	if(return_value == REG_NOMATCH) { return true; }

	return false;
}// end testEmailFormat()


bool testStudentData(struct student temp) {
	regex_t reg;
	int return_value;

	// Testing if Student Name is within length range
	if(strlen(temp.name) < 5 || strlen(temp.name) > 20) {
		displayError(E_NAME_LENGTH, temp.name);
		return true;
	}
	
	// Testing if Student Email is correct length
	if(strlen(temp.email) != 17) {
		displayError(E_EMAIL_LENGTH, temp.email);
		return true;
	}

	// Testing if Student Number is correct length
	if(strlen(temp.number) != 9) {
		displayError(E_NUMBER_LENGTH, temp.number);
		return true;
	} 
	
	// Testing if Student Number is in correct format
	return_value = regcomp(&reg, "^u[0-9]{8}$", REG_EXTENDED | REG_ICASE);
	return_value = regexec(&reg, temp.number, 0, NULL, 0);
	if(return_value == REG_NOMATCH) {
		displayError(E_NUMBER_FORMAT, temp.number);
		return true;
	}

	// Testing if Student Email is in correct format
	if(testEmailFormat(temp)) {
		displayError(E_EMAIL_FORMAT, temp.email);
		return true;
	}

	// Testing if Student Credits are within range
	if (temp.credits < 0 || temp.credits > 150) {
		char buffer[20];
        sprintf(buffer, "%.1f", temp.gpa);
        displayError(E_CREDITS_VALUE, buffer);
		return true;
	}

	// Testing if Student GPA is within range
	if(temp.gpa < 0.0 || temp.gpa > 4.0) {
		char buffer[20];
        sprintf(buffer, "%.1f", temp.gpa);
        displayError(E_GPA_VALUE, buffer);
		return true;
	}
	return false;
}// end testStudentData()