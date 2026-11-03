// Checks whether a number is a prime
#include <stdio.h>

bool is_prime(long long n);

int main(void) {
    // Ask user to input a number
    printf("Enter an integer: ");
    int number;
    scanf("%i", &number);

    // Check for prime
    bool p = is_prime(number);
    if (p) {
        printf("Number is a prime\n");
    }
    else {
        printf("Number is not a prime\n");
    }
}

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }

    for (long long i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}