// Hard coding is bad but idc too lazy
// to use args to pass it with a pipe
#include <stdio.h>
#include <string.h>

// The forbiden hardcoded size is back
#define inputSize 1000

int main() {
	FILE *inputFile;
	// Fucking install gentoo
	long target = 105950735;
	// Everything is a long bc I just
	// dont care anymore
	long i = 0;
	long j = 0;
	long num;
	long tmp;
	long tmp2;
	long data[inputSize+1];

	memset(data, 0, sizeof(data));

	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%ld ", &num) != -1) {
		// If your inputSize is below your line count
		// enjoy your segfault.
		data[i] = num;
		i++;
	}

	for (i = 0; i < inputSize; i++) {
		num = data[i];
		tmp2 = 0;
		tmp = target;
		for (j = i; j < inputSize; j++) {
			if (j != i) {
				num += data[j];
			}
			if (data[j] > tmp2) {
				tmp2 = data[j];
			}
			if (data[j] < tmp) {
				tmp = data[j];
			}
			if (num == target && data[i] != target) {
				printf("%ld\n", tmp2+tmp);
				return 0;
			}
		}	
	}


	fclose(inputFile);
	return 1;
}
