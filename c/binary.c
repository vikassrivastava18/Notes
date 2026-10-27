// Perform recursive binary search on an array of integers

#include <stdio.h>
#include "cs50.h"

bool binary(int arr[], int low, int high, int target);

int main() {
    // Binary search strictly requires a SORTED array
    int my_arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(my_arr) / sizeof(my_arr[0]); // Correct way to get size in main()
    int target = 230;

    // Call the function passing 0 as 'low' and 'size - 1' as 'high'
    if (binary(my_arr, 0, size - 1, target)) {
        printf("Element found!\n");
    } else {
        printf("Element not found.\n");
    }

    return 0;
}

bool binary(int arr[], int low, int high, int target) {
    if (low > high) {
        return false;
    }

    int mid_ind = low + (high - low) / 2;

    if (arr[mid_ind] == target) {
        return true;
    }
    else if (arr[mid_ind] > target) {
        return binary(arr, low, mid_ind-1, target);
    }
    else {
        return binary(arr, mid_ind+1, high, target);
    }
}