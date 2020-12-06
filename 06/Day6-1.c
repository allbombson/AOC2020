#include <stdio.h>
#include <string.h>

unsigned char questions[26];
unsigned short totalQuestions = 0;

void check() {
	unsigned char i;
	for (i= 0; i< 26; i++) {
		if (questions[i] == 1) {
			questions[i] = 0;
			totalQuestions++;
		}
	}
}

int main() {
	FILE *inputFile;
	unsigned int whitespace;
	unsigned char question;

	inputFile = fopen("input.txt", "r");

	memset(questions, 0, sizeof(questions));
	while (fscanf(inputFile, " %n%c", &whitespace, &question) == 1) {
		if (whitespace == 2)
			check();
		if (question >= 'A' && question <= 'Z') {
			questions[question - 'A'] = 1;
		} else if (question >= 'a' && question <= 'z') {
			questions[question - 'a'] = 1;
		}
	}
	check();

	printf("%d\n", totalQuestions);

	fclose(inputFile);
	return 0;
}
