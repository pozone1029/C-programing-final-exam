#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

struct linklist {
	int ID;
	int money;
	int posision;
	struct linklist* next;
};
struct queue {
	struct linklist* first;
};
void join( struct queue*list, int ID, int money ){
	struct linklist* newperson = (struct linklist*)malloc(sizeof(struct linklist));
	newperson->ID = ID;
	newperson->money = money;
	newperson->next = NULL;
	if (list->first == NULL) {
		list->first = newperson;
	}
	else {
		struct linklist* current = list->first;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newperson;
	}
}
void insert(struct queue* list, int ID, int money, int position) {
	struct linklist* newperson=(struct linklist*)malloc(sizeof(struct linklist));
	newperson->ID = ID;
	newperson->money = money;
	if (position == 0) {
		newperson->next = list->first;
		list->first = newperson;
	}
	else {
		struct linklist* current = list->first;
		for (int i = 0; i < position - 1; i++) {
			current = current->next;
		}
		newperson->next = current->next;
		current->next = newperson;
	}
}
void leave(struct queue* list, int position) {
	struct linklist* current = list->first;
	if (position == 0) {
		list->first=list->first->next;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			current = current->next;
		}
		current->next = current->next->next;
	}
}
void print(struct queue* list) {
	struct linklist* current = list->first;
	while (current != NULL) {
		printf("ID money: %d %d\n", current->ID, current->money);
		current = current->next;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	struct queue list;
	list.first = NULL;
	for (int i = 0; i < N; i++) {
		int size;
		scanf("%d", &size);
		switch (size) {
		case 1: {
			int position;
			scanf("%d", &position);
			leave(&list, position);
			break;
		}
		case 2: {
			int ID, money;
			scanf("%d %d", &ID, &money);
			join(&list, ID, money);
			break;
		}
		case 3: {
			int ID, money, position;
			scanf("%d %d %d", &ID, &money, &position);
			insert(&list, ID, money, position);
			break;
		}
		}
	}
	print(&list);
}