#include <stdio.h>

int is_digit(int c) {
    return c >= '0' && c <= '9'; 
}

double my_stod(const char* s, const char **endptr) {
    while (*s && !is_digit(*s) && *s != '.')
        s++;

    double n = 0.0;
    while(*s && is_digit(*s))
    {
        n = n * 10.0 + ((*s) - '0');
        s++;
    }

    if (*s == '.')
        s++;
    double r = 0.0;
    double x = 10.0;
    while(*s && is_digit(*s)) {
        r = r + ((*s) - '0') / x;
        x = x * 10.0;
        s++;
    }
	printf("next = %s\n", s);
    if(endptr != NULL)
        *endptr = s;
    return n + r;
}

int main(void) {
    char str[] = "abc123.4ssdd";
    char* next;
    double v1 = my_stod(str, &next);
    // double v2 = my_stod(next, NULL);

    printf("v1 = %lf\n", v1);
    printf("next = %s\n", next);

    return 0;
}
