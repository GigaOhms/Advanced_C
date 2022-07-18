int StringEqual(char chuoi1[], char chuoi2[]){
    for (int i = 0; i < i + 1; i++){
        if(chuoi1[i] == '\0' && chuoi2[i] == '\0')
            return 1;
        else if (chuoi1[i] == '\0' || chuoi2[i] == '\0')
            return 0;
        else if (chuoi1[i] != chuoi2[i])
            return 0;
    }
}
