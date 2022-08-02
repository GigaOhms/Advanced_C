#include <stdio.h>
#define SIZE 100
#define true 1
#define false 0

void enqueue();
void dequeue();
void show();

int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;

int main() {
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            return 0;
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 

int isFull (){
	if (Rear == SIZE - 1){
		printf("Overflow \n");
		return true;
	}
	return false;
}

int isEmpty(){
	if (Front == - 1 || Front > Rear){
        printf("Underflow \n");
        return true;
    }
	return false;
}

void show(){
    if (isEmpty() == true)
    	return;
    else {
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
} 

void enqueue(){
    int insert_item;
    if (isFull() == true)
       return;
    else {
        if (Front == - 1)
        	Front = 0;
        printf("Element to be inserted in the Queue: ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
}

void dequeue(){
    if (isEmpty() == true)
        return ;
    else {
        printf("Element removed from queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 