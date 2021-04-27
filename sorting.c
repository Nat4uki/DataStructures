//
// Created by Natsuki on 2021/4/27.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraySize = 0;

void Random(int *a, int n, int l, int r) {
    for (int i = 0; i < n; i++) {
        a[i]=rand()%(r-l+1)+l;
    }
}

void printArray(int *a,int n){
    printf("The arraySize of array = %d\n",n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int* mallocArray(){
    srand(time(0));
    arraySize = rand() % 10 + 10;
    int * a = (int*)malloc(sizeof(int) * arraySize);
    return a;
}
int main() {
    int * array = mallocArray();
//    int n = mallocArray(array);
    Random(array, arraySize, 1, 100);
    printArray(array, arraySize);
    free(array);
    return 0;
}
