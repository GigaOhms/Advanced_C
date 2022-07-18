void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// swap(&a[1], &a[2]);
// swap(&n, &m);

void insertionSort(int a[], int n){
    int k;
    for (int i = 1; i < n; i++){
        k = a[i];
        int j = i;
        while (j > 0 && a[j-1] > k){
            a[j] = a[j-1];
            j--;
        }
        a[j] = k;
    }
}

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = n-1; i > -1; i--){
        int flag = 1;
        for (int j = 0; j < i; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 0;
            }
        } if (flag) return;
    }
}

void bubbleSort2(int a[], int n){
    for (int i = n-1; i > -1; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}
