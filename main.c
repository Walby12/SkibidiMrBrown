#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum KeyWords {
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAREN,
    CLOSE_PAREN,
    SEMICOLON,
    IDENT,
};

enum KeyWords stringToEnum(char ch) {
    if (ch == '{') {
        return OPEN_BRACE;
    } else if (ch == '}') {
        return CLOSE_BRACE;
    } else if (ch == '(') {
        return OPEN_PAREN;
    } else if (ch == ')') {
        return CLOSE_PAREN;
    } else if (ch == ';') {
        return SEMICOLON;
    }
    return -1;
}

int isValidKeyword(char ch) {
    return stringToEnum(ch) != -1;
}

int lex(void) {
    FILE *test = fopen("test.skmr", "r");
    if (test == NULL) {
        perror("Error opening file");
        return -1;
    }
    char readFile[100];
    
    if (fgets(readFile, sizeof(readFile), test) != NULL) {
        for (int i = 0; i < sizeof(readFile) && readFile[i] != '\0'; i++) {
            if (isValidKeyword(readFile[i])) {
                switch (stringToEnum(readFile[i])) {
                    case OPEN_BRACE:
                        printf("OPEN_BRACE\n");
                        break;
                    case CLOSE_BRACE:
                        printf("CLOSE_BRACE\n");
                        break;
                    case OPEN_PAREN:
                        printf("OPEN_PAREN\n");
                        break;
                    case CLOSE_PAREN:
                        printf("CLOSE_PAREN\n");
                        break;
                    case SEMICOLON:
                        printf("SEMICOLON\n");
                        break;
                    default:
                        break;
                }
            }
        }
    } else {
        printf("File is empty\n");
    }
    fclose(test);
    return 0;
}

int main(void) {
    return lex();   
}
