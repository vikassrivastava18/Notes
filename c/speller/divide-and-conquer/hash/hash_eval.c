#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define N 100
#define WORD_LENGTH 256

typedef struct {
    int number;
    int count;
} dict;

unsigned int hash(const char *word);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dictionary-file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open dictionary file");
        return 1;
    }

    dict dictionary[N];
    for (int i = 0; i < N; i++) {
        dictionary[i].number = i;
        dictionary[i].count = 0;
    }

    char word[WORD_LENGTH];
    int total_words = 0;

    while (fscanf(file, "%255s", word) == 1) {
        unsigned int bucket = hash(word);
        dictionary[bucket].count++;
        total_words++;
    }

    fclose(file);

    int occupied_buckets = 0;
    int max_count = 0;

    printf("\nBucket counts:\n");
    for (int i = 0; i < N; i++) {
        printf("%2d: %d\n", dictionary[i].number, dictionary[i].count);

        if (dictionary[i].count > 0) {
            occupied_buckets++;
        }
        if (dictionary[i].count > max_count) {
            max_count = dictionary[i].count;
        }
    }

    printf("\nWords: %d\n", total_words);
    printf("Occupied buckets: %d/%d\n", occupied_buckets, N);
    printf("Largest bucket: %d word(s)\n", max_count);

    return 0;
}

unsigned int hash(const char *word)
{
    unsigned int word_value = 0;
    size_t length = strlen(word);

    for (size_t i = 0; i < length; i++) {
        unsigned char character = (unsigned char) word[i];

        if (isupper(character)) {
            word_value += (character - 'A') * i;
        } else if (islower(character)) {
            word_value += (character - 'a') * i;
        } else {
            // for "'"
            word_value += 39;
        }
    }

    return word_value % N;
}