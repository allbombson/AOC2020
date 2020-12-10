#include <stdio.h>
#include <string.h>

int main() {
	FILE *inputFile;
	unsigned short num;
	unsigned short data[1024];
	unsigned char i = 0;
	unsigned char j;
	unsigned char diff3 = 1;
	unsigned char adapterCount;

	inputFile = fopen("input.txt", "r");

	while (fscanf(inputFile, "%hd ", &num) != -1) {
		data[i] = num;
		i++;
	}
	adapterCount = i;
	
	for (i = 0; i < adapterCount; i++) {
		for (j = i + 1; j < adapterCount; j++) {
			if (data[i] > data[j]) {
				data[i] ^= data[j]; 
				data[j] ^= data[i]; 
				data[i] ^= data[j];
			}
		}
	}

	j = 1;
	for (i = 0; i < adapterCount-1; i++) {
		if (data[i+1] - data[i] == 1) {
			j++;
		} else if (data[i+1] - data[i] == 3) {
			diff3++;
		}
	}

	printf("%d %d %d\n", j*diff3, j, diff3);

	fclose(inputFile);
	return 0;
}
