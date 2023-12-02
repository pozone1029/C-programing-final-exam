#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

int main() {
	FILE* fin1;
	FILE* fin2;
	fin1 = fopen("p2_input_plaintext.txt", "r");
	fin2 = fopen("p2_input_ciphertext.txt", "r");
	int key[30];

	int i = 0;
	while(i <30){
		int word1 = fgetc(fin1);
		int word2 = fgetc(fin2);
		if (((word1 > 64) && (word1 < 91)) || ((word1 > 96) && (word1 < 123))) {
			if ((word2 - word1) < 0) {
				key[i] = word2 - word1+26;
				i += 1;
			}
			else {
				key[i] = word2 - word1 ;
				i += 1;
			}
		}
		else {
			continue;
		}
	}
	int lengh,max_lengh=0;
	for (lengh = 2; lengh <16; lengh++) {
		for (int i = 0; i < 30; i++) {
			if (i < lengh) {
				if (key[i] == key[i + lengh]) {
					continue;
				}
				else {
					break;
				}
			}
			else {
				max_lengh = lengh;
			}
			
		}
	}
	int min_lengh = 0;
	if (max_lengh == 15) {
		for (lengh = 2; lengh < 16; lengh++) {
			for (int i = 0; i < 15; i++) {
				if (i < 30/lengh) {
					if (key[i] == key[i + lengh]) {
						continue;
					}
					else {
						break;
					}
				}
				else {
					for (int i = 0; i<lengh; i++) {
						printf("%c", key[i] + 97);
					}
					return 0;
				}

			}
		}
	}
	for (int i = 0; i < max_lengh; i++) {
		printf("%c", key[i] + 97);
	}
	return 0;
}