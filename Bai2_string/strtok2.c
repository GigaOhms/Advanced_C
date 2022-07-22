#include <stdio.h>

int strcspn_t(const char *s1, const char *s2) {
	const char *s = s1;
	const char *c;
	while (*s1) {
		for (c = s2; *c; c++)
			if (*s1 == *c)
				break;
		if (*c)
			break;
		s1++;
	}
	return s1 - s;
}


char *strtok_t(char *s, const char *delim) {
	static char *old;
	if (s == NULL)
		s = old;
	if (*s == 0) {
		old = s;
		return NULL;
	}
	char *end = s + strcspn_t(s, delim);
	if (*end == 0) {
		old = end;
		return s;
	}
	*end = 0;
	old = end + 1;
	return s;
}

int main() {
	char arr[] = "We-are-learning-abffffoat-libray-stdlib";
	char *token = strtok_t(arr, "-");
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok_t(NULL, "-");
	}
	return 0;
}