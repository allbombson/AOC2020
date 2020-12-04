#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Size of input set
#define inputSize 1069

int main() {
	FILE *inputSet;
	inputSet = fopen("input.txt", "r");

	int i;
	int passVaild;
	int whitespace;
	int byr;
	int iyr;
	int eyr;
	int hgt;
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
		if (strstr(buffer,"byr:")){
			byr = atoi(&buffer[4]);
			if (byr > 1919 && byr < 2003){
				byrB = true;
			}
		}
		if (strstr(buffer,"iyr:")){
			iyr = atoi(&buffer[4]);
			if (iyr > 2009 && iyr < 2021){
				iyrB = true;
			}
		}
		if (strstr(buffer,"eyr:")){
			eyr = atoi(&buffer[4]);
			if (eyr > 2019 && eyr < 2031){
				eyrB = true;
			}
		}
		if (strstr(buffer,"hgt:")){
			hgt = atoi(&buffer[4]);
			if ((buffer[6] == 'i' && buffer[7] == 'n' && buffer[8] == 0 && hgt > 58 && hgt < 77) || (buffer[7] == 'c' && buffer[8] == 'm' && buffer[9] == 0 && hgt > 149 && hgt < 194)){
				hgtB = true;
			}
		}
		if (strstr(buffer,"hcl:")){
			if (buffer[4] == '#' && isxdigit(buffer[5]) && isxdigit(buffer[6]) && isxdigit(buffer[7]) && isxdigit(buffer[8]) && isxdigit(buffer[9]) && isxdigit(buffer[10])){
				hclB = true;
			}
		}
		if (strstr(buffer,"ecl:")){
			if (!strcmp(&buffer[4], "amb") || !strcmp(&buffer[4], "blu") || !strcmp(&buffer[4], "brn") || !strcmp(&buffer[4], "gry") || !strcmp(&buffer[4], "grn") || !strcmp(&buffer[4], "hzl") || !strcmp(&buffer[4], "oth")){
				eclB = true;
			}
		}
		if (strstr(buffer,"pid:")){
			if (isdigit(buffer[4]) && isdigit(buffer[5]) && isdigit(buffer[6]) && isdigit(buffer[7]) && isdigit(buffer[8]) && isdigit(buffer[9]) && isdigit(buffer[10]) && isdigit(buffer[11]) && isdigit(buffer[12])){
				pidB = true;
			}
		}

		
	}

	printf("%d\n", passVaild);

	fclose(inputSet);
	return 0;
}
