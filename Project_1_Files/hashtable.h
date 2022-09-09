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
	for(int index = 0; index < TABLE_SIZE; index++) {
		if(hashTable[index] != NULL) {
			printf("*************************************************************************");
			printf("\nIndex: %d\n\n> %s\t%s\t%s\t%d\t%.2lf\n\n", index, 
												   	     	 	 hashTable[index]->name,
												         	 	 hashTable[index]->number,
												         	 	 hashTable[index]->email,
												         	 	 hashTable[index]->credits,
												         	 	 hashTable[index]->gpa);
		} else { continue; }
	}
}// end displayHashTable()


void displayRecord(struct student* temp, int index) {

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
	printf("Added Student to Hash Table: %s\t\t\tTarget: %d,  Actual: %d\n", hashTable[key]->name,
																		   original_key,
																		   key);
	return;	
}// end insertStudent()


bool testEmailFormat(struct student temp) {

}// end testEmailFormat()


bool testStudentData(struct student temp) {
	bool flag = true;
	if(strlen(temp.name) < 5 || strlen(temp.name) > 20) {
		displayError(5, temp.name);
	} else if(temp.number[0] != 'u') {
		displayError(7, temp.number);
	} else if(strlen(temp.number) != 9) {
		displayError(6, temp.number);
	} else if(strlen(temp.email) != 17) {
		displayError(8, temp.email);
	} 
	
	
	
}// end testStudentData()