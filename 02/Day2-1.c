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
	int passCount;
	int passVaild;
	char letter;
	char buffer[4096];

	passVaild = 0;
	for (i = 0; i < inputSize; i++){
		memset(buffer, 0, sizeof(buffer));
		fscanf(inputSet, "%d-%d %c:%4095s", &passMin, &passMax, &letter, buffer);

		passCount = 0;
		for (j =0; j < strlen(buffer); j++){
			if (buffer[j] == letter){
				passCount++;
			}
		}
		if (passCount > (passMin - 1) && passCount < (passMax + 1)){
			passVaild++;
		}
	}
	printf("%d\n", passVaild);

	fclose(inputSet);
	return 0;
}
