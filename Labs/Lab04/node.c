/* Chang Min Bark
 * CSCI 306 Lab 04
 * Compile file for node using make node
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct node *node_create(void *data, int size);
void node_destroy(struct node *n);

struct node *node_create(void *data, int size) {
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = malloc(size);
    memcpy(n->data, data, size);
    n->size = size;
    n->next = NULL;
    return n;
};

void node_destroy(struct node *n) {
    free(n->data);
    // free(n->next); DON'T NEED THIS BECAUSE WE ARE NOT 
    // DYNAMICALLY ALLOCATING MEMORY FOR IT SEPARATELY.
    // THE MEMORY FOR THE POINTER/ADDRESS IS INCLUDED IN THE
    // malloc(sizeof(struct node)) CALL.
    free(n);
}
