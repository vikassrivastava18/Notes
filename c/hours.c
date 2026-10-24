#include <stdio.h>
#include "cs50.h"

int main(void) {
	int weeks;
	do {
		weeks = get_int("Number of weeks taking CS50: ");

	} while (weeks < 0);

	int hours[weeks];

	for (int i = 0; i < weeks; i++) {
		hours[i] = get_int("Week %i HW Hours: ", i);
	}

	char opt = get_char("Enter T for total hours, A for average hours for week: \n");

	if (opt == 'T') {
		float total = 0.0;
		for (int i = 0; i < weeks; i++) {
			total += hours[i];
		}
		printf("Total hours: %.2f\n", total);
	}
	else if (opt == 'A') {
		float average = 0;
		for (int i = 0; i < weeks; i++) {
			average += hours[i];
		}
		printf("Average hours: %.2f\n", average / weeks);

	}
}

