#include <stdio.h>

int main(void) {
	char filename[10];
	sprintf(filename, "%03i.jpg", 2);
	printf("%s\n", filename);
	return 0;
}
