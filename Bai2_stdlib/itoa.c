#include <stdio.h>

void reverse(char *str, int length){
    int start = 0;
    int end = length -1;
	char a;
    while (start < end){
		a = str[start];
		str[start] = str[end];
		str[end] = a;
        start++;
        end--;
    }
}

void dec2bin(int n, char *buffer){
	int index = 0;
    if(n == 0) buffer[index++] = '0';
    while(n > 0){
        buffer[index++] = n%2 + 48;
        n /= 2;
    }
	reverse(buffer, index);
    buffer[index] = '\0';
}

void dec2dec(int n, char *buffer){
	int index = 0;
	if(n == 0) buffer[index++] = '0';
	while (n > 0){
		buffer[index++] = n%10 + 48;
		n /= 10;
	}
	reverse(buffer, index);
	buffer[index] = '\0';
}

void dec2hex(int n, char *buffer){
	int index = 0, temp = 0;
	if(n == 0) buffer[index++] = '0';
	while (n > 0){
		temp = n%16;
		if (temp < 10)
            buffer[index++] = temp + 48;
		else
			buffer[index++] = temp + 55;
		n /= 16;
	}
	reverse(buffer, index);
	buffer[index] = '\0';
}

void itoa(int n, char buffer[], int base){
	switch (base){
		case 2:
			dec2bin(n, buffer);
			break;
		case 10:
			dec2dec(n, buffer);
			break;
		case 16:
			dec2hex(n, buffer);
			break;
	}
}

int main(){
    int a = 123456789;
    char buffer[100];
	itoa(a, buffer, 16);
	printf("%s\n", buffer);
    return 0;
}