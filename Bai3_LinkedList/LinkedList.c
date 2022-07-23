#include <stdio.h>
#include <stdlib.h>

struct List {
	int data;
	struct List *next;
};

typedef struct List *Vector;

Vector Create(int value) {
	Vector temp;
	temp = (Vector)malloc(sizeof(struct List));
	temp->next = NULL;
	temp->data = value;
	return temp;
}

Vector Push_Back(Vector node, int value) {
	Vector p, temp;
	temp = Create(value);
	if (node == NULL)
		node = temp;
	else {
		p = node;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
	return node;
}

Vector Input() {
	Vector vt = NULL;
	int n, value;
	do {
		printf("Enter N: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("Enter the value to add: ");
		scanf("%d", &value);
		vt = Push_Back(vt, value);
	}
	return vt;
}

int Get(Vector note, int index) {
	int i = 0;
	Vector p = note;
	while (p->next != NULL && i != index) {
		i++;
		p = p->next;
	}
	return p->data;
}

int Pop(Vector note) {
	if (note == NULL)
		return '\0';
	Vector p = note, q = note;
	while (p->next != NULL) {
		p = p->next;
		if (p->next == NULL)
			break;
		q = q->next;
	}
	int result = p->data;
	q->next = NULL;
	return result;
}

void ChangeValue(Vector note, int index, int value) {
	int i = 0;
	Vector p = note;
	while (p->next != NULL && i != index) {
		i++;
		p = p->next;
	}
	p->data = value;
}

int main() {
	Vector vt = Input();
	ChangeValue(vt, 4, 10);
	int a = Pop(vt);
	Push_Back(vt, 5);
	printf("data: %d - pop = %d", Get(vt, 4), a);
	return 0;
}