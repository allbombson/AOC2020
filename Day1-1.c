// Shitty o(n^2) algo

#include <stdio.h>

// Size of input set
#define inputSize 200

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int inputArray[inputSize];
	int i;
	int j;
	int num1;

	for (i = 0; i < inputSize; i++){
		fscanf(inputSet, "%d", &inputArray[i] );
	}

	for (i = 0; i < inputSize; i++){
		num1 = 2020 - inputArray[i];
		for (j = 0; j < inputSize; j++){
			if (inputArray[j] == num1){
				printf("%d\n", inputArray[j] * inputArray[i]);
				return 0;
			}
		}
	}

	fclose(inputSet);

	return 1;
}
