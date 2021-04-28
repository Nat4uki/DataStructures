//
// Created by Natsuki on 2021/4/27.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
/*
 * do
 *  swapped = false
 *  for i = 1 to indexOfLastUnsortedElement-1
 *      if leftElement > rightElement
 *          swap(leftElement, rightElement)
 *          swapped = true
 * while swapped*/
void bubbleSort(int *a,int arraySize){
    for (int i=0;i<arraySize-1;i++){
        for (int j=0;j<arraySize-1-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] =temp;
            }
        }
    }
    return;
}
/*
 * repeat (numOfElements -1) times
 *  set the first unsorted element as the minimum
 *  for each of the the unsorted elements
 *      if element < currentMinimum
 *          set element as new minimum
 *  swap minimum with first unsorted position
 * */
void selectionSort(int *a,int arraySize){
    int currentMinIndex;
    for (int i =0;i<arraySize-1;i++){
        currentMinIndex = i;
        for (int j=i;j<arraySize;j++){
            if(a[j]<a[currentMinIndex]){
                currentMinIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[currentMinIndex];
        a[currentMinIndex] = temp;
    }
    return;
}

void insertionSort(int *a,int arraySize){
    int currentInt;
    for (int i=1;i<arraySize;i++){
        currentInt = a[i];
        for (int j = i;j>0;j--){
            if (currentInt<a[j-1]){
                a[j] = a[j-1];
                if(j==0){
                    a[0] = currentInt;
                }
            }else{
                a[j] = currentInt;
                break;
            }
        }
    }
    return;
}
int main() {
    int arraySize = 20;
    int *array = mallocArray(arraySize,1, 100);
    printArray(array,arraySize);
//    bubbleSort(array,arraySize);
//    selectionSort(array,arraySize);
    insertionSort(array,arraySize);
    printArray(array,arraySize);
    freeArray(array);
    return 0;
}
