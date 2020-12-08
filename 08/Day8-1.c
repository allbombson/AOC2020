// Arc this is becuase you kept nagging me to write a VM
#include <stdio.h>
#include <string.h>

int main() {
	FILE *inputFile;
	char buffer[4];
	short acc = 0;
	unsigned short len = 0;
	short memoryAddress;
	// 2K of ROM for our program.
	unsigned char opROM[1024];
	short argROM[1024];
	// Another 1k for keeping track of addresses for loop detection
	unsigned short table[1024];

	inputFile = fopen("input.txt", "r");

	// Clear garbage in table and load data into ROM
	memset(table, 0, sizeof(table));
	while (fscanf(inputFile, "%s %hd ", buffer, &argROM[len]) != -1) {
		opROM[len] = buffer[0];
		opROM[len + 1] = 0;
		len++;
	}

	// VM/Bytecode time
	for (memoryAddress = 0; memoryAddress < len;) {
		if (opROM[memoryAddress] == 'j' && argROM[memoryAddress] == 0) {
			break;
		}
		if (table[memoryAddress] == 1) {
			break;
		}
		table[memoryAddress] = 1;

		switch (opROM[memoryAddress]) {
			case 'n':
				memoryAddress++;
				break;
			case 'a':
				acc = acc + argROM[memoryAddress];
				memoryAddress++;
				break;
			case 'j':
				memoryAddress = memoryAddress + argROM[memoryAddress];
				break;
		}
		printf("%0#5x: %c %d\n", memoryAddress, opROM[memoryAddress], argROM[memoryAddress]);
	}

	printf("%d\n", acc);

	fclose(inputFile);
	return 0;
}
