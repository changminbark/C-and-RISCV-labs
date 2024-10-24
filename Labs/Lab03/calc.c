/* 
 * Chang Min Bark
 * File name: calc.c
 * Compile with: gcc -std=c99 calc.c -o calc
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isInteger(char *s);
bool isValid(char *s);
char *operation;
int returnVal = 0;

int main(int argc, char * argv[]) {
    if (argc == 1) {
        printf("Usage: ./calc <operation> <arguments...>\n");
        return 0;
    }

    if (argc < 3) {
        printf("More arguments are needed\n");
        exit(1);
    }

    if (isValid(argv[1])) {
        operation = argv[1];
    } else {
        printf("Unsupported function, try: add, mult, div, or len\n");
        exit(1);
    }
    

    if (strcmp(operation, "len")==0) {
        for (int i = 2; i < argc; i++) {
            if (isInteger(argv[i])) {
                printf("Invalid operands\n");
                exit(1);
            } else {
                returnVal += strlen(argv[i]);
            }
        }
    } else {
        if (argc < 4) {
            printf("More arguments are needed\n");
            exit(1);
        }
		if (strcmp(operation, "div")==0 || strcmp(operation, "mult")==0) {
			returnVal = 1;
		}
        for (int i = 2; i < argc; i++) {
            if (!(isInteger(argv[i]))) {
                printf("Invalid operands\n");
                exit(1);
            } else if (strcmp(operation, "add")==0) {
                returnVal += strtol(argv[i], NULL, 10);
            } else if (strcmp(operation, "mult")==0) {
				returnVal *= strtol(argv[i], NULL, 10);
			} else if (strcmp(operation, "div")==0) {
                if (strtol(argv[i], NULL, 10) == 0) {
                    printf("Divide by zero");
                    exit(1);
                }
				returnVal /= strtol(argv[i], NULL, 10);
			}
        }
    } 

    printf("%d", returnVal);
    return 0;
}

bool isValid(char *s) {
    if (strcmp(s, "add")==0 ||
            strcmp(s, "len")==0 ||
            strcmp(s, "mult")==0 ||
            strcmp(s, "div")==0) {
        return true;
    } else {
        return false;
    }
}


bool isInteger(char *s) {
    while (*s) {
        if (!(*s >= '0' && *s <= '9')) {
            return false;
        }
        s++;
    }

    return true;
}
