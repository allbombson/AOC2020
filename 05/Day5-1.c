// This code has been written for performance on a 8bit computer
// using a 6502 such as a Commodore 64. The compiler I am using
// supports up to C89(ANSI) as a result I have to follow some retarded
// rules such as all local variables need to be declared at the start
// of a function. The compiler in question is cc65 --> https://cc65.github.io/
#include <stdio.h>
#include <string.h>

// Size of input set
#define inputSize 850

unsigned char buffer[11];
int main() {
	FILE *inputSet;
	unsigned short i;
	unsigned char j;
	unsigned short id;
	unsigned char row;
	unsigned char seat;

	inputSet = fopen("input.txt", "r");

	id = 0;
	for (i = 0; i < inputSize; i++){
		fscanf(inputSet, "%10s", buffer);
		row = 0;
		seat = 0;
		for (j = 0; j < 7; j++){
			if (buffer[j] == 'F' || buffer[j] == 'f'){
				row = row << 1;
			}
			if (buffer[j] == 'B' || buffer[j] == 'b'){
				row = row << 1;
				row++;
			}
		}
		for (j = 0; j < 3; j++){
			if (buffer[j+7] == 'R' || buffer[j+7] == 'r'){
				seat = seat << 1;
				seat++;
			}
			if (buffer[j+7] == 'L' || buffer[j+7] == 'l'){
				seat = seat << 1;
			}
		}

		if (row*8+seat > id){
			id = row*8+seat;
		}
	}

	printf("%d\n", id);

	fclose(inputSet);
	return 0;
}
