#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define SIZE 10

void quickSort(int array[], int leftBound, int rightBound);
int partition(int a[], int left, int right);

int main(){
    srand(time(NULL));
    int unSort[SIZE];
    for(int s = 0; s < SIZE; s++){
        unSort[s] = rand();
    }
    int length = sizeof(unSort)/sizeof(unSort[0]);
    for(int i=0; i<SIZE;i++){
        printf("A[%d]: %d\n", i, unSort[i]);
    }
    quickSort(unSort, 0, length-2);
    for(int p =0; p<SIZE;p++){
        printf("sorted\nA[%d]: %d\n", p, unSort[p]);
    }
    return 0;
}

void quickSort(int array[], int leftBound, int rightBound){
    int part; 

    if(leftBound < rightBound){  
        part = partition(array, leftBound, rightBound);
        quickSort(array, leftBound, part); //smaller part
        quickSort(array, part+1, rightBound); //larger part
   }   
}

//Look at implementing pre-increment instead of post increment for faster/efficient code

int partition(int a[], int left, int right){
    int pivot, i, k;
    int mid = (left+right)/2;
    pivot = mid;
    i = left-1;
    k = right+1;

    while(1){
        while(a[i]<a[pivot]){
         i++;
     } 
        while(a[k]>a[pivot]){
         k--;
        }
        if(i>=k){
            return k;
        }
    int t = a[i];
    a[i] = a[k];
    a[k] = t;   
    }
}
