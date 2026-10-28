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

#define N 10
typedef unsigned char BYTE;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int p = toupper(word[0]) - 'A';
    return p % N;
}

bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source != NULL)
    {
        char buffer[LENGTH+1];

        while (fscanf(source, "%46s", buffer) != EOF) {
            printf("%s\n", buffer);
            int h = hash(buffer);

            node *new_node = malloc(sizeof(node));
            strcpy(new_node->word, buffer);

            if (table[h] == NULL) {
                table[h] = new_node;
            }
            else {
                node *last_node = *table[h];

                do {
                    last_node = table[h]->next;
                }
                while (last_node->next != NULL)
            }

            last_node->next = new_node;
            
        }
    }

    // Close the dictionary file
    fclose(source);
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
