#include <stdio.h>
#include <string.h>

#define blockSize 25

int main() {
	FILE *inputFile;
	long vaild = 0;
	long num = 0;
	long numSearch;
	long set = 0;
	long i = 0;
	long j;
	long k;
	long prev[blockSize+1];
	
	memset(prev, 0, sizeof(prev));

	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%ld ", &num) != -1) {
		if (set > blockSize-1) {
			for (j = 0; j < blockSize; j++) {
				for (k = 0; k < blockSize; k++) {
					if (prev[k] + prev[j] == num) {
						vaild++;
					}
				}
			}
			if (i == blockSize) {
				i = 0;
			}
			prev[i] = num;
			if (vaild != 0) {
				vaild = 0;
			} else {
				printf("%ld\n", num);
				return 0;
			}
		} else {
			prev[i] = num;
			set++;
		}

		i++;
	}
	fclose(inputFile);
	return 1;
}
