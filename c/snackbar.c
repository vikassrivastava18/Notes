// Practice using structs and linear search

#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#define NUM_ITEMS 5

typedef struct {
    string name;
    float price;
} menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to the menu
void add_items(void);
    
    
// Calculate total cost
float get_cost(string item);

int main(void) {

    // Add items to menu
    add_items();

    printf("\nWelcome to Beach Burger Snack!");
    printf("Choose from the following menu to order. Press enter when done.");

    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%s: $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("\n");
    float total = 0;

    while (true) {
        // Get user orders
        string item = get_string("Enter order name: ");
        if (strlen(item) == 0) {
            break;
        }
        total += get_cost(item);

    }

    printf("Total amount: %.2f", total);

}

void add_items(void) {
    menu[0].name = "Burger";
    menu[0].price = 9.5;
    menu[1].name = "Hot Dog";
    menu[1].price = 5;
    menu[2].name = "Fries";
    menu[2].price = 5;
    menu[3].name = "Cold Brew";
    menu[3].price = 3;
    menu[4].name = "Water";
    menu[4].price = 2;
}

float get_cost(string item) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (strcmp(menu[i].name, item) == 0) {
            return menu[i].price;
        }
    }
    return 0.0;
}
