#define _CRT_SECURE_NO_WARNINGS
#define true
#define nullptr
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct item {
	int* value;
	struct item *next;
} item;

item *head = NULL, *tail = NULL;

item* create() {
	int value;
	item* i = malloc(sizeof(item));
	if (i == NULL) {
		puts("\noops");
		return;
	}
	else {
		puts("Enter the item:\n");
		if (scanf("%d", &value) == 1);
		else {
			puts("incorrect input");
			exit(0);
		}
		i->value = value;
		i->next = head;
		head = i;
	}
	return i;
}

void display() {
	item* i;
	i = head;
	if (i == NULL) {
		puts("List is empty!");
		return;
	}
	else {
		puts("\nElements are:");
		while (i != NULL)
		{
			printf("%d\n", i->value);
			i = i->next;
		}
		puts("----------------------------");
	}
}

void delete() {
	item *a, *b = NULL;
	if (head == NULL) printf("\nEmpty list");
	else if (head->next == NULL) {
		printf("\nDeleted: %d\n", head->value);
		free(head);
		head = NULL;
		return;
	}
	else {
		a = head;
		while (a->next != NULL) {
			b = a;
			a = a->next;
		}
		b->next = NULL;
		printf("\nDeleted: %d\n", a->value);
		free(a);
	}
}

void add() {
	item *a, *b;
	int value;
	a = (item*)malloc(sizeof(item));
	if (a == NULL) {
		puts("\noops");
		return;
	}
	else {
		puts("Enter the item\n");
		if (scanf("%d", &value) == 1);
		else {
			puts("incorrect input");
			exit(0);
		}
		a->value = value;
		if (head == NULL) {
			a->next = NULL;
			head = a;
		}
		else {
			b = head;
			while (b->next != NULL) b = b->next;
			b->next = a;
			a->next = NULL;
		}
	}
}

void clear() {
	if (head == NULL) {
		puts("Error: List is empty");
		return;
	}
	item* curr = head;
	item* next;
	while (curr->next != tail) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(tail);
	head = NULL;
	tail = NULL;
	return;
}

void find() {
	item* a;
	int value, i = 0, j;
	a = head;
	if (a == NULL) {
		puts("\nList is empty!\n");
		return;
	}
	else
	{
		puts("\nEnter the element to search:\n");
		if (scanf("%d", &value) == 1);
		else {
			puts("incorrect input");
			exit(0);
		}
		while (a != NULL)
		{
			if (a->value == value) {
				printf("\nPosition of the element is %d\n", i + 1);
				j = 0;
				break;
			}
			else j = 1;
			i++;
			a = a->next;
		}
		if (j == 1) puts("\nElement is not found\n");
	}
}

int main() {
	int input;
	while (1) {
		puts("Press one of these keys to do what you need\n1 - add the first element of linked list\n2 - add the element to the end of the list\n3 - delete the last element of the list\n4 - watch the existing list\n5 - clear the list\n6 - find the position of needed element\n7 - exit the program\n");
		if (scanf("%d", &input) == 1);
		else {
			puts("incorrect input");
			exit(0);
		}
		switch (input) {
		case 1:
			create();
			continue;
		case 2:
			add();
			continue;
		case 3:
			delete();
			continue;
		case 4:
			display();
			continue;
		case 5:
			clear();
			continue;
		case 6:
			find();
			continue;
		case 7:
			return;
		} 
	}
	return 0;
}
