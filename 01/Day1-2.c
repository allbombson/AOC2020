// Shitty o(n^3) algo

#include <stdio.h>

// Size of input set
#define inputSize 200

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int inputArray[inputSize];
	int i;
	int j;
	int k;
	int num1;
	int num2;

	for (i = 0; i < inputSize; i++){
		fscanf(inputSet, "%d", &inputArray[i] );
	}

	for (i = 0; i < inputSize; i++){
		num1 = 2020 - inputArray[i];
		for (j = 0; j < inputSize; j++){
			num2 = num1 - inputArray[j];
			for (k = 0; k < inputSize; k++){
				if (inputArray[k] == num2){
					printf("%d\n", inputArray[i] * inputArray[j] * inputArray[k]);
					return 0;
				}
			}
		}
	}

	fclose(inputSet);

	return 1;
}
