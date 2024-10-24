/* Chang Min Bark
 * CSCI 306 Lab 04
 * Compile file for strnode using make strnode
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strnode.h"

struct strnode *strnode_create(char *s, int length);

struct strnode *strnode_create(char *s, int length) {
    struct strnode *node;
    node = malloc(sizeof(struct strnode));
    node->str = malloc(strlen(s) + 1);
    strcpy(node->str, s);
    node->length = length;
    node->next = NULL;
    return node;
}
