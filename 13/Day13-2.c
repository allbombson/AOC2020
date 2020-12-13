#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *inputFile;
	unsigned int id[10];
	unsigned long i = 0;
	unsigned long j;
	unsigned long m;
	unsigned char size;

	// Stuff for gdb
	system("clear");

	inputFile = fopen("inputFiltered2.txt", "r");

	fscanf(inputFile, "%lu ", &j);
	while (fscanf(inputFile, "%d,", &id[i]) != -1) {
		i++;
	}
	size = i;

	i = 0;
	m = 1;
	for(j = 0; j < size; j++){
		// skip empty slots 
		if(id[j] == 0)
			continue;
		while((i + j) % id[j] != 0){
			i += m; 
		}
		m *= id[j];  
	}

	printf("%lu\n", i);

	fclose(inputFile);
	return 0;
}
