#include <stdio.h>
#include <string.h>

// Size of input set
#define inputSize 1000

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int i;
	int j;
	int passMin;
	int passMax;
	int passVaild;
	char letter;
	char buffer[4096];

	passVaild = 0;
	for (i = 0; i < inputSize; i++){
		memset(buffer, 0, sizeof(buffer));
		fscanf(inputSet, "%d-%d %c:%4095s", &passMin, &passMax, &letter, buffer);

		if ((buffer[passMin - 1] == letter && buffer[passMax - 1] != letter) || (buffer[passMax - 1] == letter && buffer[passMin - 1] != letter)){
			passVaild++;
		}
	}
	printf("%d\n", passVaild);

	fclose(inputSet);
	return 0;
}
