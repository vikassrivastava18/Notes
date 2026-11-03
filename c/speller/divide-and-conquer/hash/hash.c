#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 100

unsigned int hash(const char *word);

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage ./hash word\n");
        return 1;
    }

    int h = hash(argv[1]);
    printf("Hash of word %s is: %i\n", argv[1], h);

    return 0;
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


