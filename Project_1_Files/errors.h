#pragma once // Prevents the header file from loading multiple times


enum ERROR_NUMBER
{
    E_MISSING_COMMAND,  //  0
    E_FILE_NOT_FOUND,   //  1
    E_BLANK_RECORD,     //  2
    E_CORRUPT_RECORD,   //  3
    E_SHORT_RECORD,     //  4
    E_DUPLICATE_NAME,   //  5
    E_NAME_LENGTH,      //  6
    E_NUMBER_LENGTH,    //  7
    E_NUMBER_FORMAT,    //  8
    E_EMAIL_LENGTH,     //  9
    E_EMAIL_FORMAT,     // 10
    E_CREDITS_VALUE,    // 11
    E_GPA_VALUE,		// 12							
};


void displayError(int error, char* errorInfo);

void displayError(int error, char* errorInfo) {
    char message[100];
    
    switch (error) {
    case E_MISSING_COMMAND:
        strcpy(message,  "Missing Command");
        break;
    case E_FILE_NOT_FOUND:
        strcpy(message, "No File Given");
        break;
    case E_BLANK_RECORD:
        strcpy(message, "Blank Record Given");
        break;
    case E_CORRUPT_RECORD:
        strcpy(message, "Corrupt Record");
        break;
    case E_SHORT_RECORD:
        strcpy(message, "Record Too Short");
        break;
    case E_DUPLICATE_NAME:
        strcpy(message, "Duplicate Name Found");
        break;
    case E_NAME_LENGTH:
        strcpy(message, "Student Name Not Between 5 and 20 Characters");
        break;
    case E_NUMBER_LENGTH:
        strcpy(message, "Student Number Not 9 Characters");
        break;
    case E_NUMBER_FORMAT:
        strcpy(message, "Student Number is Invalid");
        break;
    case E_EMAIL_LENGTH:
        strcpy(message, "Student Email Not 17 Characters");
        break;
    case E_EMAIL_FORMAT:
        strcpy(message, "Student Email Format is Invalid");
        break;
    case E_CREDITS_VALUE:
        strcpy(message, "Student Credit is Not Less Than 150");
        break;
    case E_GPA_VALUE: 
        strcpy(message, "Student GPA Not Less Than 4.0");
    default:
        break;
    }// end switch

    if(strcmp(message, "Blank Record Given") == 0) {
        printf("Error %d %s \n", error, message);    
    } else {
	    printf("Error %d (%s): %s\n", error, message, errorInfo);
    }
}