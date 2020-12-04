#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Size of input set
#define inputSize 1069

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int i;
	int passVaild;
	int whitespace;
	bool byrB = false;
	bool iyrB = false;
	bool eyrB = false;
	bool hgtB = false;
	bool hclB = false;
	bool eclB = false;
	bool pidB = false;
	char buffer[4096];

	passVaild = 0;
	memset(buffer, 0, sizeof(buffer));
	for (i = 0; i < (inputSize*8); i++){
		fscanf(inputSet, " %n%4095s", &whitespace, buffer);

		if (whitespace == 2){
			if (byrB && iyrB && eyrB && hgtB && hclB && eclB && pidB){
				printf("%s\n", buffer);
				passVaild++;
			}
			byrB = false;
			iyrB = false;
			eyrB = false;
			hgtB = false;
			hclB = false;
			eclB = false;
			pidB = false;
		}

		// YandreDev Moment
		if (strstr (buffer,"byr:")){
			byrB = true;
		}
		if (strstr (buffer,"iyr:")){
			iyrB = true;
		}
		if (strstr (buffer,"eyr:")){
			eyrB = true;
		}
		if (strstr (buffer,"hgt:")){
			hgtB = true;
		}
		if (strstr (buffer,"hcl:")){
			hclB = true;
		}
		if (strstr (buffer,"ecl:")){
			eclB = true;
		}
		if (strstr (buffer,"pid:")){
			pidB = true;
		}

		
	}
	// YandreDev Moment
	if (strstr (buffer,"byr:")){
		byrB = true;
	}
	if (strstr (buffer,"iyr:")){
		iyrB = true;
	}
	if (strstr (buffer,"eyr:")){
		eyrB = true;
	}
	if (strstr (buffer,"hgt:")){
		hgtB = true;
	}
	if (strstr (buffer,"hcl:")){
		hclB = true;
	}
	if (strstr (buffer,"ecl:")){
		eclB = true;
	}
	if (strstr (buffer,"pid:")){
		pidB = true;
	}
	if (byrB && iyrB && eyrB && hgtB && hclB && eclB && pidB){
		printf("%s\n", buffer);
		passVaild++;
	}

	printf("%d\n", passVaild);
	printf("%s\n", buffer);

	fclose(inputSet);
	return 0;
}
