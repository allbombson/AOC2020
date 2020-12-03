// I littearly wrote part of a game engine by mistake.
// Write games don't play em
#include <stdio.h>
#include <string.h>

// Size of input set
#define inputSize 323

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int y;
	int x;
	int num;
	int hits;
	char buffer[32768];

	x = 0;
	num = 0;
	memset(buffer, 0, sizeof(buffer));
	for (y = 0; y < inputSize;){
		fscanf(inputSet, "%c", &buffer[x]);
		if (buffer[x] == 10){
			if (num == 0){
				num = x;
			}
			y++;
		}
		x++;
	}
	x = 0;
	hits = 0;
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		printf("X:%d, Y:%d I:%c\n", x, y, buffer[x+(num+1)*y]);
		//buffer[x+(num+1)*y] = 88;
		if (buffer[x+(num+1)*y] == 35){
			hits++;
		}
		x = x + 3;
	}
	printf("%s", buffer);
	printf("%d\n", hits);

	fclose(inputSet);
	return 0;
}
