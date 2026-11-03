#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Max word length
#define LENGTH 45
// Bucket size
#define N 100

unsigned int hash(const char *word);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *table[N];
bool load(const char *dictionary);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dictionary-file\n", argv[0]);
        return 1;
    }

    if (!load(argv[1])) {
        return 1;
    }

    printf("Bucket counts:\n");
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (node *current = table[i]; current != NULL; current = current->next) {
            count++;
        }
        printf("%3d: %d\n", i, count);
    }

    return 0;
}

bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL) {
        perror("Could not open dictionary");
        return false;
    }
    
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


