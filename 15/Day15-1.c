#include <stdio.h>

unsigned long numbers[30000030];
int main() {
	FILE *inputFile;
	unsigned long i = 0;
	unsigned long j;
	unsigned long round;

	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%lu, ", &numbers[i]) != -1) {
		i++;
	}

	for (round = i; round < 2021; round++) {
		numbers[round] = 0;
		for (j = round-1; j > 0; j--) {
			if (numbers[j-1] == numbers[round-1]) {
				numbers[round] = round-j;
				break;
			}
		}
		for (j = round-1; j > 0; j--) {
			printf("J: %lu %lu\n", j, numbers[j-1]);
		}
		printf("ROUND: %lu\n", round);
	}

	printf("%lu\n", numbers[2020-1]);

	fclose(inputFile);
	return 0;
}
