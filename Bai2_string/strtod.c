#include <stdio.h>

int is_digit(int c) {
    return c >= '0' && c <= '9'; 
}

double strtod_t(const char* s, const char **endptr) {
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
    if(endptr != NULL)
        *endptr = s;
    return n + r;
}

int main(void) {
    char str[] = "abc123.4s7.85sdd";
    char* next;
    double v1 = strtod_t(str, &next);
    double v2 = strtod_t(next, NULL);

    printf("v1 = %lf\n", v1);
    printf("v2 = %lf\n", v2);

    return 0;
}