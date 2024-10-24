/**
 * Chang Min Bark
 * CSCI306
 * Make pcalc.c using make pcalc
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "stack.h"

bool isInteger(char *s);

int main(int argc, char *argv[]) {
    struct stack *s = stack_create();

    float op1;
    float op2;
    float res;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "+") == 0 ||
            strcmp(argv[i], "-") == 0 ||
            strcmp(argv[i], "x") == 0 ||
            strcmp(argv[i], "/") == 0 ||
            strcmp(argv[i], "^") == 0) {
            stack_pop(s, &op2, sizeof(float));
            stack_pop(s, &op1, sizeof(float));
            if (strcmp(argv[i], "+") == 0) {
                res = op1 + op2;
            } else if (strcmp(argv[i], "-") == 0) {
                res = op1 - op2;
            } else if (strcmp(argv[i], "x") == 0) {
                res = op1 * op2;
            } else if (strcmp(argv[i], "/") == 0) {
                res = op1 / op2;
            } else if (strcmp(argv[i], "^") == 0) {
                res = pow(op1, op2);
            }
            stack_push(s, &res, sizeof(float));
        } else if (isInteger(argv[i])) {
            sscanf(argv[i], "%f", &op1);
            stack_push(s, &op1, sizeof(float));
        }
    }
    while (!stack_isempty(s)) { 
        stack_pop(s, &res, sizeof(float));
        printf("%.6f\n", res);
    }
    stack_destroy(s);
    return 0;
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
