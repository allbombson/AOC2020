#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

unsigned short i = 0;
unsigned short chars;
unsigned short lines = 0;
unsigned char inputArray[32768];
unsigned char buffer[sizeof(inputArray)];

void GameOfLife() {
	char alive;
	for (i = 0; i < chars; i++) {
		alive = 0;
		buffer[i] = inputArray[i];
		if (inputArray[i-1] == '#')
		   alive++;	
		if (inputArray[i+1] == '#') 
		   alive++;	
		if (inputArray[i-lines] == '#') 
		   alive++;	
		if (inputArray[i-lines-1] == '#') 
		   alive++;	
		if (inputArray[i-lines-2] == '#') 
		   alive++;	
		if (inputArray[i+lines] == '#') 
		   alive++;	
		if (inputArray[i+lines+1] == '#') 
		   alive++;	
		if (inputArray[i+lines+2] == '#')
		   alive++;	
		if (inputArray[i] == 'L' && alive == 0) {
			buffer[i] = '#';
			// printf("\033[H%s\n", buffer);
		}
		if (inputArray[i] == '#' && alive > 3) {
			buffer[i] = 'L';
			// printf("\033[H%s\n", buffer);
		}
	}
}

int main() {
	FILE *inputFile;
	char n;
	short g = 0;

	// Idk how to do this so just gonna use system() :(
	// system("clear");
	memset(inputArray, 0, sizeof(inputArray));
	memset(buffer, 0, sizeof(buffer));
	inputFile = fopen("input.txt", "r");

	while ((n = fgetc(inputFile)) != EOF) {
		if (lines == 0 && n == 10) {
			lines = i;
		}
		inputArray[i] = n;
		i++;
	}

	chars = i;

	n = 0;
	while (n == 0) {
		GameOfLife();
		for (i =0; i < chars; i++) {
			if (inputArray[i] == buffer[i]) {
				g++;
			}
		}
		if (g == chars) {
			n = 1;
		} else {
			for (i = 0; i < chars; i++) {
				inputArray[i] = buffer[i];
			}
			// usleep(300000);
		}
		g = 0;
	}

	g = 0;
	for (i = 0; i < chars; i++) {
		if (inputArray[i] == '#') {
			g++;
		}
	}

	printf("%hd\n", g);

	fclose(inputFile);
	return 0;
}
