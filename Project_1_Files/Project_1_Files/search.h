#pragma once // Prevents the header file from loading multiple times


enum SEARCH_NUMBER {
    CREDITS_EQUAL,  //  0
    CREDITS_LESS,   //  1
    CREDITS_MORE,   //  2
    EMAIL,          //  3
    EMAIL_PART,     //  4
    FULL_NAME,      //  5
    FIRST_NAME,     //  6
    LAST_NAME,      //  7
    GPA_EQUAL,      //  8
    GPA_LESS,       //  9
    GPA_MORE,       // 10
    NUMBER,         // 11
    NUMBER_PART,    // 12
};

void performSearch(struct student* array[], char* type, char* string);

void performSearch(struct student* array[], char* type, char* string) {
    // int instruction = type;

    // char* string_search;
    // double gpa_search = 0.0;
    // int credits_to_search = 0;
    // char* end;

    // switch (instruction) {
    //     case CREDITS_EQUAL:
    //         credits_to_search = strtol(string, &end, 10);
    //         printf("%d", CREDITS_EQUAL);
    //         break;
    //     case CREDITS_LESS:
    //         credits_to_search = strtol(string, &end, 10);
    //         printf("%d", CREDITS_LESS);
    //         break;
    //     case CREDITS_MORE:
    //         credits_to_search = strtol(string, &end, 10);
    //         printf("%d", CREDITS_MORE);
    //         break;
    //     case EMAIL:
    //         strcpy(string_search, string);
    //         printf("%d", EMAIL);
    //         break;
    //     case EMAIL_PART:
    //         strcpy(string_search, string);
    //         printf("%d", EMAIL_PART);
    //         break;
    //     case FULL_NAME:
    //         strcpy(string_search, string);
    //         printf("%d", FULL_NAME);
    //         break;
    //     case FIRST_NAME:
    //         strcpy(string_search, string);
    //         printf("%d", FIRST_NAME);
    //         break;
    //     case LAST_NAME:
    //         strcpy(string_search, string);
    //         printf("%d\n", LAST_NAME);
    //         break;
    //     case GPA_EQUAL:
    //         gpa_search = atof(string);
    //         break;
    //     case GPA_LESS:
    //         gpa_search = atof(string);
    //         break;
    //     case GPA_MORE:
    //         gpa_search = atof(string);
    //         break;
    //     case NUMBER:
    //         strcpy(string_search, string);
    //         break;
    //     case NUMBER_PART:
    //         strcpy(string_search, string);
    //         break;
    //     default:
    //         break;
    // }//end switch
	
}