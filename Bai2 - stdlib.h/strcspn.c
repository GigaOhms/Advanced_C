#include <stdio.h>

int test_strcspn(char *a, char *b){
    int i = 0, min = -1;
    while (*b){
        for (i = 0; *(a+i) != '\0'; i++)
            if (*b == *(a + i) && (min > i || min == -1) )
                min = i;
		b++;
	}
    if (min == -1) return i;
    return min;
}

int main(void) {
	char a[] = "ABCDEF4960910";
	char b[] = "M";
	int len = test_strcspn(a, b);
	printf("%d\n", len);
    return 0;
}
