#include <stdio.h>

void delay1s(){
	for (int i = 0; i < 100000000; i++);
}

void delay2s(){
	for (int i = 0; i < 300000000; i++);
}

void task1(){
	static int count = 0;
	count++;
	printf("Count_1: %d\n", count);
	delay1s();
}

void task2(){
	static int count = 0;
	count++;
	printf("Count_2: %d\n", count);
	delay2s();
}

int main(){
	while (1){
		task1();
		task2();
	}
	return 0;
}
