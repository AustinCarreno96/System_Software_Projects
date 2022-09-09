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
	printf("%d, %s\n", error, errorInfo);
}