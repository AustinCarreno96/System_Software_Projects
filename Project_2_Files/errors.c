#include "headers.h"


void displayError(int errorType, char* errorInfo) {
    switch(errorType) {
        case BLANK_RECORD:
            printf("ERROR: Source File Contains Blank Lines.\n");
            break;
        case DUPLICATE:
            printf("ERROR: Duplicate Symbol Name (%s) Found in Source File.\n", errorInfo);
            break;
        case FILE_NOT_FOUND:
            break;
        case ILLEGAL_OPCODE_DIRECTIVE:
            printf("ERROR: Illegal Opcode or Directive (%s) Found in Source File.\n", errorInfo);
            break;
        case ILLEGAL_SYMBOL:
            printf("ERROR: Symbol Name (%s) Cannot be a Command or Directive", errorInfo);
            break;
        case MISSING_COMMAND_LINE_ARGUMENTS:
            break;
        case OUT_OF_MEMORY:
            printf("ERROR: Program Address (%s) Exceeds Maximum Memory Address [0x8000].\n", errorInfo);
            break;
        case OUT_OF_RANGE_BYTE:
            break;
        case OUT_OF_RANGE_WORD:
            printf("ERROR: Word Value (%s) Out of Range [-16,777,216 to 16,777,215].\n", errorInfo);
            break;
        default:
            break;
    }
}