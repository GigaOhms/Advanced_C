double test_atof(char *string){
    double result = 0, count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == '.'){
            count++;
            continue;
        }
        if (count){
            count *= 10;
            result = result + (double)(string[i] - 48)/count;
        } else 
            result = result*10 + (string[i] - 48);
    }
    return result;
}
