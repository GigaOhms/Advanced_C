#include <stdio.h>

#define MAX 100
#define true 1
#define false 0

int stack[MAX];
int MyIndex = 0;

int isFull() {
	if (MyIndex == MAX - 1){
		printf("Stack is Full\n");
		return true;
	}
	return false;
}

int isEmpty() {
	if (MyIndex == -1){
		printf("Stack is Empty\n");
		return true;
	}
	return false;
}

void push() {
	if (isFull() == true) 
		return;
	else {
		int data;
		printf("Enter element: ");
		scanf("%d", &data);
		stack[++MyIndex] = data;
	}
}

void pop() {
	if (isEmpty() == true) {
		return;
	} else 
		printf("Deleted element: %d\n", stack[MyIndex--]);
}

void top() {
	if (isEmpty() == true) {
		return;
	} else 
		printf("Top element is: %d\n", stack[MyIndex]);
}

void size(){
	printf("Size of Stack is: %d\n", MyIndex);
}

int main() {
	for (int i = 0; i < 5; i++)
		push();
	top();
	size();
	pop();
	pop();
	top();
	size();
	return 0;
}