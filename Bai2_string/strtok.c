#include <stdio.h>

int strcspn_t(const char *s1, const char *s2){
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

int strspn_t(const char *s1, const char *s2){
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

char *__strtok_rr (char *s, const char *delim, char **save_ptr){
	char *end;
	if (s == NULL)
    	s = *save_ptr;
	if (*s == '\0'){
    	*save_ptr = s;
      	return NULL;
    }
	/* Scan leading delimiters.  */
  	s += strspn_t (s, delim);
	if (*s == '\0'){
    	*save_ptr = s;
    	return NULL;
    }
	/* Find the end of the token.  */
	end = s + strcspn_t (s, delim);
	if (*end == '\0'){
    	*save_ptr = end;
    	return s;
    }
	*end = '\0';
	*save_ptr = end + 1;
	return s;
}

char *strtok_t(char *s, const char *delim){
	static char *olds;
	return __strtok_rr (s, delim, &olds);
}

int main(){
    char arr[] = "We-are-learning-aboat-libray-stdlib";
    char *token = strtok_t(arr, "-");
    while (token != NULL){
        printf("%s\n", token);
        token = strtok_t(NULL, "-");
    }
    return 0;
}
