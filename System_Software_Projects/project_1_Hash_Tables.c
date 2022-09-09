#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256    // max length of string(char array)
#define TABLE_SIZE 10       // size of hashtable, should be changed later to amount of rows in csv.


// Struct for student objects
typedef struct {
    char name[MAX_NAME_LEN];
    char n_number[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    int credits_earned;
    double gpa;

} student;


// Creates student object, calls hash_key function, and returns the key to main for later use
student create_student(student *student_table) {
    student student_1 = {.name = "", .n_number = "", .email = "", .credits_earned = 0, .gpa = 0.0};
    printf("Name: ");
    scanf("%s", student_1.name);
    
    printf("N Number: ");
    scanf("%s", student_1.n_number);
    
    printf("Email Address: ");
    scanf("%s", student_1.email);
    
    printf("Credits Earned: ");
    scanf("%d", &student_1.credits_earned);

    printf("GPA: ");
    scanf("%lf", &student_1.gpa);

    return student_1;
}// end create_student()


// Creates a key for students in hash table
int hash_function(student *student_table) {
    int hash_value = 0;
    student stu = create_student(student_table);

    for(int index = 0; index < strlen(stu.name); index++) {
        hash_value += stu.name[index];
        hash_value = (hash_value * stu.name[index]) % TABLE_SIZE;
    }

    return hash_value;
}// end hash_key()






// char *argv[]     MIGHT NEED THIS LATER
int main() {
    student student_table[TABLE_SIZE];      // Hash Table
    

    int hash_key = hash_function(student_table);
    printf("Name: %s\nEmail Address: %s\n\n", student_table[hash_key].name, student_table[hash_key].email);

    // beginning of getting input from csv file
    // FILE *file_pointer;
    // file_pointer = fopen(argv[0], "r");





    return 0;
}// end main()