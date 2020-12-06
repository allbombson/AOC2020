#include <stdio.h>
#include <string.h>

unsigned char questions[26];
unsigned char lines = 0;
unsigned short totalQuestions = 0;

void check() {
	unsigned char i;
	for (i= 0; i< 26; i++) {
		if (questions[i] == lines) {
			totalQuestions++;
		}
		questions[i] = 0;
	}
	lines = 0;
}

int main() {
	FILE *inputFile;
	unsigned int whitespace;
	unsigned char question;

	inputFile = fopen("input.txt", "r");

	memset(questions, 0, sizeof(questions));
	while (fscanf(inputFile, " %n%c", &whitespace, &question) == 1) {
		if (whitespace >= 1)
			lines++;
		if (whitespace == 2) {
			check();
		}
		if (question >= 'A' && question <= 'Z') {
			questions[question - 'A']++;
		} else if (question >= 'a' && question <= 'z') {
			questions[question - 'a']++;
		}
	}
	lines++;
	check();

	printf("%d\n", totalQuestions);

	fclose(inputFile);
	return 0;
}
