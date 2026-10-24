// Check if a password has at least one lowercase letter, uppercase letter, number and symbol

// #include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cs50.h"

bool valid(string password);

int main(void) {
    string password = get_string("Enter your password: ");

    if (valid(password)) {
        printf("Your password is valid!\n");
    } else {
        printf("Your password is invalid.\n");
    }
}

bool valid(string password) {
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_symbol = false;

    for (int i = 0; i < strlen(password); i++) {
        if (ispunct((unsigned char)password[i])) {
            has_symbol = true;
        }
        if (islower(password[i])) {
            has_lower = true;
        }
        if (isupper(password[i])) {
            has_upper = true;
        }
        if (isdigit(password[i])) {
            has_digit = true;
        }
    }
    return has_lower && has_upper && has_digit && has_symbol;
}