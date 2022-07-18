int test_atoi(char *string){
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
        result = result*10 + (string[i] - 48);
    return result;
}
