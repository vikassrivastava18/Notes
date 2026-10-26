// Find the maximum in an array

#include <stdio.h>
#include "cs50.h"

int max(int arr[], int n);

int main (void) {
    int n;

    do {
        n = get_int("Number of items: ");        
    }
    while (n <= 0);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = get_int("Enter element %i: ", i);
    }

    printf("Max of the numbers: %i.\n", max(arr, n));
}

int max(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
