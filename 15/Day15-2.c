#include <stdio.h>
#include <string.h>

unsigned long numbers[30000030];
unsigned long numbers2[30000030];
int main() {
	FILE *inputFile;
	unsigned long i = 0;
	//unsigned long j;
	unsigned long round;

	memset(numbers2, 0, sizeof(numbers2));
	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%lu, ", &numbers[i]) != -1) {
		numbers2[numbers[i]] = i;
		i++;
	}

	printf("ROUND: 0 %lu %lu\n", numbers2[numbers[0]], numbers[0]);
	printf("ROUND: 1 %lu %lu\n", numbers2[numbers[1]], numbers[1]);
	printf("ROUND: 2 %lu %lu\n", numbers2[numbers[2]], numbers[2]);
	for (round = i; round < 30000001; round++) {
		numbers[round] = 0;
		//for (j = round-1; j > 0; j--) {
		if (numbers[numbers2[numbers[round-1]]] == numbers[round-1]) {
			numbers[round] = round-1-numbers2[numbers[round-1]];
			//break;
		}
		//}
		//for (j = round-1; j > 0; j--) {
		//	printf("J: %lu %lu\n", j, numbers[j-1]);
		//}
		numbers2[numbers[round-1]] = round-1;
		printf("ROUND: %lu %lu %lu\n", round, numbers2[numbers[round]], numbers[round]);
	}

	printf("%lu\n", numbers[30000000-1]);

	fclose(inputFile);
	return 0;
}
