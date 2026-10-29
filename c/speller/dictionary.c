// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

#define N 500
typedef unsigned char BYTE;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int h = hash(word);

    if (table[h] == NULL) {
        return false;
    }

    node *word_bucket = table[h];

    if (strcmp(word_bucket->word, word) == 0) {
        return true;
    }
    while (word_bucket->next != NULL) {
        word_bucket = word_bucket->next;

        if (strcmp(word_bucket->word, word) == 0) {
            return true;
        }
    }
    if (strcmp(word_bucket->word, word) == 0) {
        return true;
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int word_int = 0;
    int l = strlen(word);

    for (int i = 0; i < l; i++) {
        if (isupper(word[i])) {
            word_int += (word[i]) - 'A';
        }
        else {
            word_int += (word[i]) - 'a';
        }

    }
    return word_int % N;
}


bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source != NULL)
    {
        char buffer[LENGTH+1];        

        while (fscanf(source, "%46s", buffer) != EOF) {
            // Define the hash and nodes to add to table
            int h = hash(buffer);
            node *new_node = malloc(sizeof(node));
            node *last_node = table[h];

            // Copy the word from buffer, add NULL to next
            strcpy(new_node->word, buffer);
            new_node->next = NULL;

            if (table[h] == NULL) {
                table[h] = new_node;                
            }
            else {
                while (last_node->next != NULL) {
                    last_node = last_node->next;
                }
                last_node->next = new_node;
            }                        
        }
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
