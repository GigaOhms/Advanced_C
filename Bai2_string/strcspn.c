#include <stdio.h>

int strcspn_1(char *a, char *b){
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

int strcspn_2(const char *s1, const char *s2){
  	const char *s = s1;
  	const char *c;

  	while (*s1){
    	for (c = s2; *c; c++)
			if (*s1 == *c)
				break;
    	if (*c)
			break;
      	s1++;
    }
  return s1 - s;
}

int main(void) {
	char a[] = "ABCDEF4960910";
	char b[] = "C";
	int len = strcspn_2(a, b);
	printf("%d\n", len);
    return 0;
}
