/**
 * Chang Min
 * CSCI306 
 * Make file using make stack
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct stack *stack_create();
int stack_isempty(struct stack *s);
void stack_destroy(struct stack *s);
void stack_push(struct stack *s, void *src, int size);
void stack_pop(struct stack *s, void *dest, int size);

struct stack *stack_create() {
    struct stack *s;
    s = malloc(sizeof(struct stack));
    s->top = NULL;
    return s;
}

int stack_isempty(struct stack *s) {
    if (s->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void stack_destroy(struct stack *s) {
    if (stack_isempty(s) == 1) {
        free(s);
    } else {
        while (s->top != NULL) {
            void *temp = malloc(s->top->size);
            stack_pop(s, temp, s->top->size);
            free(temp);
        }
        free(s);
    }
}

void stack_push(struct stack *s, void *src, int size) {
    struct node *n = node_create(src, size);
    n->next = s->top;
    s->top = n;
}

void stack_pop(struct stack *s, void *dest, int size) {
    struct node *n = s->top;
    memcpy(dest, s->top->data, size);
    s->top = s->top->next;
    node_destroy(n);
}
