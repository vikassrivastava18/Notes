#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

int main(void) {
	int n = 5;
	int *ptr;

	person *new_person = malloc(sizeof(person));
	printf("%p", new_person);

	free(ptr);

}
