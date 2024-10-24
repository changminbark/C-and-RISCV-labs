/*
 * Implements a dictionary's functionality
 * Chang Min
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Maximum number of words in the dictionary
#define N 150000

#define BINS 27

// array of dictionary words
char words[BINS][N][LENGTH+1];

// number of words in the dictionary
int num_words = 0;

// This has function sums all of the ASCII/int values of each letter and then
// takes the mod BINS of that sum to return the index of the bin the word belongs
// in
unsigned int hash(const char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += (int)word[i];
    }
    return sum % BINS;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Preprocessing (change word to lowercase)
    char lower_word[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++) {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[strlen(word)] = '\0';

    int bin = hash(lower_word);
    for (int i = 0; i < num_words; i++) {
        if ((strcmp(lower_word, words[bin][i])) == 0) return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary_filename)
{
    FILE *f = fopen(dictionary_filename, "r");
    if (f == NULL) return false;
    
    char word[LENGTH + 1];

    while (fscanf(f, "%s", word) != EOF) {
        int bin = hash(word);

        strcpy(words[bin][num_words], word);

        num_words++;
    }
    
    fclose(f);
    return true;
}

// Return the number of words stored in the dictionary.
unsigned int size(void)
{
    return num_words;

}
