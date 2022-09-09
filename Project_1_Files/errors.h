#pragma once // Prevents the header file from loading multiple times


enum ERROR_NUMBER
{
    E_MISSING_COMMAND,
    E_FILE_NOT_FOUND,
    E_BLANK_RECORD,
    E_CORRUPT_RECORD,
    E_SHORT_RECORD,
    E_DUPLICATE_NAME,
    E_NAME_LENGTH,
    E_NUMBER_LENGTH,
    E_NUMBER_FORMAT,
    E_EMAIL_LENGTH,
    E_EMAIL_FORMAT,
    E_CREDITS_VALUE,
    E_GPA_VALUE,										
};


void displayError(int error, char* errorInfo);

void displayError(int error, char* errorInfo) {
    char message[100];
    
    switch (error) {
    case 0:
        strcpy(message,  "Missing Command");
        break;
    case 1:
        strcpy(message, "No File Given");
        break;
    case 2:
        strcpy(message, "Corrupt Record");
        break;
    case 3:
        strcpy(message, "Record Too Short");
        break;
    case 4:
        strcpy(message, "Duplicate Name Found");
        break;
    case 5:
        strcpy(message, "Student Name Not Between 5 and 20 Characters");
        break;
    case 6:
        strcpy(message, "Student Number Not 9 Characters");
        break;
    case 7:
        strcpy(message, "Student Number is Invalid");
        break;
    case 8:
        strcpy(message, "Student Email Not 17 Characters");
        break;
    case 9:
        strcpy(message, "Student Email Format is Invalid");
        break;
    case 10:
        strcpy(message, "Student Credit is Not Less Than 150");
        break;
    case 11:
        strcpy(message, "Student GPA Not Less Than 4.0");
        break;
    default:
        break;
    }// end switch

	printf("Error (%d): %s\n", error, message);
}