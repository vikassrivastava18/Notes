// Generates nth fibonacci number.

#include <stdio.h>
#include <stdlib.h>

long long fibonacci(int n);


int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage ./fibonacci number\n");
        return 1;
    }
    int n = atoi(argv[1]);
    long long f = fibonacci(n);
    printf("Fibonacci of number %i is: %lld\n", n, f);
    return 0;
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