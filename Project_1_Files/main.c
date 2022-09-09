#include "headers.h"

#define INPUT_BUF_SIZE 60 // Size of the buffer used to read records from input file
#define	SEARCH_BUF_SIZE 25 // Size of the buffer used to read records from search file

struct student createStudent(char record[]);
void processInputFile(struct student* hash_table[], char* filename);
bool testRecord(char record[]);

int main(int argc, char *argv[]) {
    char*  file_name = argv[1];
    struct student* hash_table[TABLE_SIZE] = { NULL };    // Creating an array of TABLE_SIZE that holds pointers to student structs


    processInputFile(hash_table, file_name);    // Processing the file and getting student data
    displayHashTable(hash_table);
    
    return 0;
}// end main()


struct student createStudent(char record[]) {
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// strcpy() - copies string data from one variable to another
	// strtol() - converts a string to its integer value
	// atof() 	- converts a string to its double value
	
    char* end;

    // creating temp student struct
    struct student new_student = {.name = "", 
                                  .number = "", 
                                  .email = "", 
                                  .credits = 0, 
                                  .gpa = 0.0};
	char* token = strtok(record, ",");		    // separating the record by commas (delimiter)
    
    int count = 0;
    while(token) {
        switch (count) {
        case 0:
            strcpy(new_student.name, token);
            break;
        case 1:
            strcpy(new_student.number, token);
            break;
        case 2:
            strcpy(new_student.email, token);
            break;
        case 3:
            new_student.credits = strtol(token, &end, 10);
            break;
        case 4:
            new_student.gpa = atof(token);
            break;
        
        default:
            break;
        }//end switch
        
        token = strtok(NULL, ",");
        count++;
    }// end while

    return new_student;
}// end createStudent()


void processInputFile(struct student* hash_table[], char* filename) {
	// Do not forget to use the following functions:
	// memset() - fill the buffer array with the specified character
    FILE *input;
	char* record = NULL;
    size_t len = 0;
    ssize_t read = 0;

	input = fopen(filename, "r");

	if(input == NULL) {
		displayError(E_FILE_NOT_FOUND, filename);
		exit(0);
	} else {
        // look into fgets instead of getline
        while((read = getline(&record, &len, input)) != -1) {
            if(!testRecord(record)) {
                displayError(3, record);
            } else {
                struct student temp_student = createStudent(record);
                insertStudent(hash_table, &temp_student);          // inserting student into hashtable
            }
			// memset(record, 0, INPUT_BUF_SIZE);                           // resetting memory at the record array for new record
        } // end while loop
	}// end if / else
}// end processInputFile()


bool testRecord(char record[]) {
    bool flag = true;
    int comma_counter = 0;
    char comma = ',';

    for(int index = 0; index < INPUT_BUF_SIZE; index++) { if(record[index] == ',') { comma_counter++; } }

    if(comma_counter != 4) { flag = false; }
    
    return flag;
}// end testRecord()