#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
#include <string.h>

struct AoT_Player {
	int player_id;
	char name[10];
}player[] = { {2,"Micasa"},{4,"Armin"},{1,"Eren"},{5,"Levi"},{3,"Crista"} };
 
int main() {
	struct AoT_Player tran;
	for (int j = 4; j >0; j--) {
		for (int i = 0; i <= j-1; i++) {
			if (player[i].player_id > player[i + 1].player_id) {
				tran = player[i];
				player[i] = player[i + 1];
				player[i + 1] = tran;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("{%d,%s}\n", player[i].player_id, player[i].name);
	}
	return 0;
}