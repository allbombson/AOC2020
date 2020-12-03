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
	int hits1;
	int hits2;
	int hits3;
	int hits4;
	int hits5;
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
	hits1 = 0;
	hits2 = 0;
	hits3 = 0;
	hits4 = 0;
	hits5 = 0;

	// One
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		if (buffer[x+(num+1)*y] == 35){
			hits1++;
		}
		x = x + 1;
	}
	// Two
	x = 0;
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		if (buffer[x+(num+1)*y] == 35){
			hits2++;
		}
		x = x + 3;
	}
	// Three
	x = 0;
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		if (buffer[x+(num+1)*y] == 35){
			hits3++;
		}
		x = x + 5;
	}
	// Four
	x = 0;
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		if (buffer[x+(num+1)*y] == 35){
			hits4++;
		}
		x = x + 7;
	}
	// Five
	x = 0;
	for (y = 0; y < inputSize; y++){
		while(x > num-1){
			x = x - num;
		}
		if (buffer[x+(num+1)*y] == 35){
			hits5++;
		}
		x = x + 1;
		y++;
	}

	printf("%s", buffer);
	printf("%u\n", hits1 * hits2 * hits3 * hits4 * hits5);

	fclose(inputSet);
	return 0;
}
