#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inputStruct {
	char op;
	short arg;
};

struct inputStruct inputData[1024];
int main() {
	FILE *inputFile;
	char buf[2];
	short num;
	unsigned short i = 0;
	unsigned short j;
	unsigned short inputSize;
	unsigned short x = 0;
	unsigned short wx = 10;
	unsigned short y = 0;
	unsigned short wy = 1;

	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%c%hd ", buf, &num) != -1) {
		inputData[i].op = buf[0];
		inputData[i].arg = num;
		//printf("%c %hd\n", inputData[i].op, inputData[i].arg);
		i++;
	}

	inputSize = i;

	for (i = 0; i < inputSize; i++) {
		if (inputData[i].op == 'N')
			wy += inputData[i].arg;
		if (inputData[i].op == 'E')
			wx += inputData[i].arg;
		if (inputData[i].op == 'S')
			wy -= inputData[i].arg;
		if (inputData[i].op == 'W')
			wx -= inputData[i].arg;
		if (inputData[i].op == 'F') {
			x += wx*inputData[i].arg;
			y += wy*inputData[i].arg;
			//wx += wx*inputData[i].arg;
			//wy += wy*inputData[i].arg;
		}
		if (inputData[i].op == 'R') {
			printf("ARG:%d\n", inputData[i].arg/90);
			for (j = 0; j < inputData[i].arg/90; j++) {
				wx ^= wy;
				wy ^= wx;
				wx ^= wy;
				wy = -wy;
				//wx = wy;
				//wy = -wx;
				printf("WX:%hd WY:%hd\n", wx, wy);
			}
		}
		if (inputData[i].op == 'L') {
			printf("ARG:%d\n", inputData[i].arg/90);
			for (j = 0; j < inputData[i].arg/90; j++) {
				wx ^= wy;
				wy ^= wx;
				wx ^= wy;
				wx = -wx;
				printf("WX:%hd WY:%hd\n", wx, wy);
			}
		}
		printf("X:%hd Y:%hd\n", x, y);
		printf("WX:%hd WY:%hd\n", wx, wy);
	}

	printf("X:%hd Y:%hd\n", x, y);

	fclose(inputFile);
	return 0;
}
