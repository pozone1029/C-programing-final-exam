#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
#include <string.h>

int main() {
	FILE* fin;
	fin = fopen("p1_input.txt", "r");
	FILE* fout;
	fout = fopen("p1_output.txt", "w");
	char key[16];
	scanf("%s", key);
	for (int i = 0; i < strlen(key); i++) {
		if ((key[i] > 64) && (key[i] < 91)) {
			key[i] = key[i] - 65;
		}
		else {
			key[i] = key[i] - 97;
		}
	}
	char word;
	int count = 0;
	if (fin != NULL) {
		while ((word = getc(fin)) != EOF) {
			int key_number = 0;
			if ((word > 64) && (word < 91)) {
				key_number = count % strlen(key);
				word += key[key_number];
				if (word > 90) {
					word -= 26;
				}
				fprintf(fout, "%c", word);
				count += 1;
				if (count >= strlen(key)) {
					count -= strlen(key);
				}
			}
			else if ((word > 96) && (word < 123)) {
				key_number = count % strlen(key);
				int w = word;
				if ((w + key[key_number]) > 126) {
					word -= 26;
				}
				word += key[key_number];
				if (word > 122) {
					word -= 26;
				}
				fprintf(fout, "%c", word);

				count += 1;
				if (count >= strlen(key)) {
					count -= strlen(key);
				}
			}
			else {
				fprintf(fout, "%c", word);
			}
		}
	}
	else {
		printf("error");
	}
	fclose(fout);
	return 0;
}