// Find the first 10 fibonacci numberes that are also prime
#include <stdio.h>

bool is_prime(long long n);
long long fibonacci(int n);

int main(void) {
    // 
    long long arr[10];
    int count = 0;
    int fib_count = 1;

    // Keep looking for Fibonaccis that are also prime
    while (count < 10) {
        long long f = fibonacci(fib_count);

        if (is_prime(f)) {
            arr[count] = f;
            count += 1;
        }

        fib_count += 1;
    }

    // Print the output
    for (int i = 0; i < count; i++) {
        printf("Number %d is %lld\n", i + 1, arr[i]);
    }

    return 0;
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

long long fibonacci(int n) {
    
    if (n == 1 || n == 2) {
        return 1;
    }
    long long prev = 1;
    long long pre_prev = 1;
    long long fib;

    for (int i = 3; i <= n; i++) {
        fib = prev + pre_prev;
        long long temp = prev;
        prev = fib;
        pre_prev = temp;
    }

    return fib;    
}