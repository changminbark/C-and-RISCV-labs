/* Chang Min Bark
 * CSCI 306 Lab 04
 * Header file for strnode
 */

#ifndef STRNODE_H_
#define STRNODE_H_
struct strnode {
    char *str;
    int length;
    struct strnode *next;
};

struct strnode *strnode_create(char *s, int length);

#endif
