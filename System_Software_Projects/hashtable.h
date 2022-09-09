#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#pragma once // Prevents the header file from loading multiple times


// Constants for the Student Structure
#define EMAIL_SIZE 18
#define NAME_SIZE 24
#define NUMBER_SIZE 10


struct student {
	char name[NAME_SIZE];
	char number[NUMBER_SIZE];
	char email[EMAIL_SIZE];
	int credits;
	double gpa;
};


// Constants for the Hash Table
#define HASH_TABLE_SEGMENTS 7 // Used in the hashing algorithm
#define MOD_SIZE 5 // Used in the hashing algorithm
#define NEW_LINE 10 // Newline character code
#define TABLE_SIZE 35 // Number of available spaces

int computeHash(char* studentName);
void displayHashTable(struct student* hashTable[]);
// void displayRecord(struct student* temp, int index);
void insertStudent(struct student* hashTable[], struct student* temp);
// bool testEmailFormat(struct student temp);
// bool testStudentData(struct student temp);


int computeHash(char* input) {
	int hash_value = 0;

    for(int index = 0; index < strlen(input); index++) {
        hash_value += input[index];
    }// end for loop

	return hash_value % TABLE_SIZE;
}// end computeHash()


void displayHashTable(struct student* hashTable[]) {
	
	for(int index = 0; index < TABLE_SIZE; index++) {
		struct student student_printed = *(hashTable[index]);
		printf("> %s\t\n\n", student_printed.name);
	}
	
}// end displayHashTable()


// void displayRecord(struct student* temp, int index) {

// }// end displayRecord()



void insertStudent(struct student* hashTable[], struct student* temp) {
	// Do not forget to use the malloc() function to reserve space for the student structure
	// Do not forget to use the strcpy() function to store the string data in the hash table
	
	struct student temp_2 = *temp;		// dereferncing pointer to another temp structure
	struct student final_struct;
	int temp_key = 0;
	// final_struct = (struct student*) malloc(sizeof(struct student));
	
	// storing temp structure elements to final_struct
	strcpy(final_struct.name, temp_2.name);
	strcpy(final_struct.number, temp_2.number);
	strcpy(final_struct.email, temp_2.email);
	
	final_struct.credits = temp_2.credits;
	final_struct.gpa = temp_2.gpa;
	// printf("******************************************************************\n");
	// printf("> %-2s | %-2s | %-2s | %-2d | %.2lf\n\n", final_struct.name,
	// 												  final_struct.number,
	// 												  final_struct.email,
	// 												  final_struct.credits, 
	// 												  final_struct.gpa);
	int hash_key = computeHash(final_struct.name);	// computing hash key
	// printf("Before While Loop: %d\n\n", hash_key);

	// if (hashTable[hash_key] != NULL) {
	// 	for(int new_key; new_key < TABLE_SIZE; new_key++) {
	// 		if (hashTable[new_key] == NULL) { 
	// 			hash_key = new_key;
	// 			break; 
	// 		}		
	// 	}
	// }
	// printf("After While Loop: %d\n\n", hash_key);
	hashTable[hash_key] = (struct student*) malloc(sizeof(struct student));	// allocating memory in hashtable where the key is


	hashTable[hash_key] = &final_struct;
	return;
}// end insertStudent()


// bool testEmailFormat(struct student temp) {

// }// end testEmailFormat()


// bool testStudentData(struct student temp) {
	
// }// end testStudentData()