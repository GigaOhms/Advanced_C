#include <stdio.h>

#define MAX 100

int stack[MAX];
int MyIndex = 0;

int isFull(int MyIndex) {
	if (MyIndex == MAX - 1)
		return 1;
	return 0;
}

int isEmpty(int MyIndex) {
	if (MyIndex == 0)
		return 1;
	return 0;
}

void push(int data) {
	if (isFull(MyIndex)) {
		printf("Stack is Full\n");
		return;
	}
	stack[MyIndex++] = data;
}

int pop() {
	if (isEmpty(MyIndex)) {
		printf("Stack is Empty\n");
	} else {
		int result = stack[MyIndex - 1];
		stack[MyIndex--] = '\0';
		return result;
	}
}

int top() {
	if (isEmpty(MyIndex)) {
		printf("Stack is Empty\n");
	} else
		return stack[MyIndex];
}

int main() {
	push(8);
	push(7);
	push(6);
	push(5);
	push(4);
	for (int i = 0; i < 6; i++)
		printf("%d ", pop());
	return 0;
}