#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *inputFile;
	unsigned int depart;
	unsigned int id[10];
	unsigned char i = 0;
	unsigned int j;
	unsigned int k;
	unsigned char size;
	unsigned char found;

	// Stuff for gdb
	system("clear");

	inputFile = fopen("inputFiltered.txt", "r");

	fscanf(inputFile, "%d ", &depart);
	while (fscanf(inputFile, "%d,", &id[i]) != -1) {
		i++;
	}
	size = i;

	found = 0;
	j = depart;
	while (found == 0) {
		for (i = 0; i < size; i++) {
			if (j%id[i] == 0) {
				k = id[i];
				found = 1;
				break;
			}
		}
		j++;
	}

	printf("%d\n", (j-depart-1)*k);

	fclose(inputFile);
	return 0;
}
