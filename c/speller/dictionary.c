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

// Hash table
node *table[N];

// Dictionary count
int dict_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int h = hash(word);    
    node *word_bucket = table[h];

    while (word_bucket != NULL) {
        if (strcasecmp(word_bucket->word, word) == 0) {
            return true;
        }
        word_bucket = word_bucket->next;
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
            word_int += ((word[i]) - 'A') * i;
        }
        else if (islower(word[i])){
            word_int += ((word[i]) - 'a') * i;
        }
        else {
            word_int += 39;
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
            dict_count += 1;

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
    return dict_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *n = table[0];
    while (n != NULL) {
        node *temp = n->next;
        free(n);
        n = temp;
    }
    return true;
}