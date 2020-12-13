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
	unsigned short y = 0;
	// Face East
	char dirx = 1;
	char diry = 0;

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
			y += inputData[i].arg;
		if (inputData[i].op == 'E')
			x += inputData[i].arg;
		if (inputData[i].op == 'S')
			y -= inputData[i].arg;
		if (inputData[i].op == 'W')
			x -= inputData[i].arg;
		if (inputData[i].op == 'F') {
			x += dirx*inputData[i].arg;
			y += diry*inputData[i].arg;
		}
		if (inputData[i].op == 'R') {
			printf("ARG:%d\n", inputData[i].arg/90);
			for (j = 0; j < inputData[i].arg/90; j++) {
				if (dirx == 1) {
					// South
					dirx = 0;
					diry = -1;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (diry == -1) {
					// West
					dirx = -1;
					diry = 0;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (dirx == -1) {
					// North
					dirx = 0;
					diry = 1;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (diry == 1) {
					// East
					dirx = 1;
					diry = 0;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				}
			}
		}
		if (inputData[i].op == 'L') {
			printf("ARG:%d\n", inputData[i].arg/90);
			for (j = 0; j < inputData[i].arg/90; j++) {
				if (dirx == 1) {
					// North
					dirx = 0;
					diry = 1;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (diry == 1) {
					// West
					dirx = -1;
					diry = 0;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (dirx == -1) {
					// South
					dirx = 0;
					diry = -1;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				} else if (diry == -1) {
					// East
					dirx = 1;
					diry = 0;
					printf("XDir:%hd YDir:%hd\n", dirx, diry);
				}
			}
		}
		printf("X:%hd Y:%hd\n", x, y);
	}

	printf("X:%hd Y:%hd\n", x, y);

	fclose(inputFile);
	return 0;
}
