
#include <stdio.h>
#include <pthread.h>
 
void delay1s(){
	for (int i = 0; i < 100000000; i++);
}
void delay2s(){
	for (int i = 0; i < 300000000; i++);
}
void *task1(void *data){
	static int count = 0;
	while(1){
		count++;
		printf("Count_1: %d\n", count);
		delay1s();
	}
}
void *task2(void *data){
	static int count = 0;
	while(1){
		count++;
		printf("Count_2: %d\n", count);
		delay2s();
	}
}
int main(){
	pthread_t id1, id2;
	pthread_create(&id1, NULL, &task1, NULL);
	pthread_create(&id2, NULL, &task2, NULL);
	while(1){
		printf("Test\n");
		delay1s();
	}
}