/* 
 * Chang Min Bark
 * File name: cmd_args.c
 * Compile with: gcc -std=c99 cmd_args.c -o cmd_args
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isInteger(char *s);
bool isValid(char *s);

int main(int argc, char * argv[]) {
    if (argc < 3) {
        printf("Incorrect number of arguments.\n");
        exit(1);
    }

    if (isValid(argv[1])) {
        printf("\"%s\" is a valid command\n", argv[1]);
    } else {
        printf("\"%s\" is an invalid command\n", argv[1]);
    }

    for (int i = 2; i < argc; i++) {
        if (isInteger(argv[i])) {
            printf("%s is an integer\n", argv[i]);
        } else {
            printf("%s is not an integer\n", argv[i]);
        }
    }

    // for (int i = 0; i < argc; ++i)
	  // printf("The %dth argument is %s\n", i, argv[i]);
    return 0;
}

bool isValid(char *s) {
    if (strcmp(s, "add")==0 ||
            strcmp(s, "sub")==0 ||
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
