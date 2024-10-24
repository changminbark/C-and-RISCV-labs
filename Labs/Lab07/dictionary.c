/*
 * Implements a dictionary's functionality
 * Chang Min
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Maximum number of words in the dictionary
#define N 150000

// array of dictionary words
char words[N][LENGTH+1];

// number of words in the dictionary
int num_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    for (int i = 0; i < num_words; i++) {
        if ((strcasecmp(word, words[i])) == 0) return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary_filename)
{
    FILE *f = fopen(dictionary_filename, "r");
    if (f == NULL) return false;

    int i = 0;
    while (fscanf(f, "%s", words[i]) != EOF) {
        i++;
        num_words ++;
    }
    
    fclose(f);
    return true;
}

// Return the number of words stored in the dictionary.
unsigned int size(void)
{
    return num_words;

}
