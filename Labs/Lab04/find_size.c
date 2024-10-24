/* Chang Min Bark
 * CSCI 306 Lab 04
 * Create file using make find_size
 */
#include <stdio.h>

struct course_t {
    int ID;
    int enrollment;
    char title[32];
    char prof[32];
};

struct course_node_t {
    int ID;
    int enrollment;
    char *title;
    char *prof;
    struct course_node_t *next;
};

int main() {
    printf("%ld\n", sizeof(struct course_t));
    printf("%ld\n", sizeof(struct course_node_t));
    return 0;
}
