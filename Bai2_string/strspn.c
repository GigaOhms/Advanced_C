#include <stdio.h>

int strspn_t(const char *s1,	const char *s2){
  	const char *s = s1;
  	const char *c;

  	while (*s1){
      	for (c = s2; *c; c++)
	  		if (*s1 == *c)
	    		break;
      	if (*c == '\0')
			break;
      	s1++;
    }
	return s1 - s;
}

int main(void) {
	char a[] = "ABCDEF4960910";
	char b[] = "4";
	int len = strspn_t(a, b);
	printf("%d\n", len);
    return 0;
}