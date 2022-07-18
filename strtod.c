#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

double test_strtod(char *string, char **ptr){
    int j = 0;
    double result = 0, count = 0;
    char *newPtr = (char *) malloc(20);
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] >= '0' && string[i] <= '9' && !result){
            while ((string[i] >= '0' && string[i] <= '9') || string[i] == '.'){
                if (string[i] == '.'){
                    count++; i++;
                    continue;
                }
                if (count){
                    count *= 10;
                    result = result + (double)(string[i] - 48)/count;
                } else 
                    result = result*10 + (string[i] - 48);
                i++;
            }
            i--;
        }
        else newPtr[j++] = string[i];
    }
    newPtr[j] = '\0';
    free(*ptr);
    *ptr = newPtr;
    return result;
}



int main(){
    int val;
    double vall;
    char str[20];
    char *ptr;
    strcpy(str, "heohello123");
    val = test_strtod(str, &ptr);
    printf("chuoi: %s\n", ptr);
    printf("val = %d", val);
    free(ptr);
    return 0;
}
