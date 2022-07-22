#include <stdio.h>

// char *strtok_t(char *s, const char *delim){
// 	static char *old;
// 	if (s != NULL)
// 		*old = s;
// 	if (!(*old))
// 		return 0;
// 	for (int i = 0; 1; i++){
// 		for ()
// 	}
	
// }

void ccc(char *s){
	static char *old;
	if (s != NULL)
		old = s;
	printf("%s\n", old);
}

int main(){
    char arr[] = "We-are-learning-aboat-libray-stdlib";
    // char *token = strtok_t(arr, "-");
    // while (token != NULL){
    //     printf("%s\n", token);
    //     token = strtok_t(NULL, "-");
    // }
	ccc(arr);
    return 0;
}