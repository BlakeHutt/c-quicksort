#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define SIZE 10
void quickSort(int array[], int leftBound, int rightBound);
int partition(int a[], int left, int right);

int main(){
    srand(time(NULL));
 //   int unSort[SIZE];
    int test[] = {1, 4, 6, 8, 2, 3, 9, 7};
/*    for(int s = 0; s < SIZE; s++){
        unSort[s] = rand();
    }
 */   
   // int length = sizeof(unSort)/sizeof(unSort[0]);
    printf("unsorted\n");
    for(int i=0; i<8; i++){
        printf("test[%d]: %d\n", i, test[i]);
    }
    quickSort(test, 0, 8-1);
    printf("now sorted\n");
    for(int i = 0; i<8;i++){
        printf("test[%d]: %d\n",i, test[i]);
    }    
    return 0;
}



void quickSort(int *array, int leftBound, int rightBound){
    
    

    if(leftBound < rightBound){
           
        int part = partition(array, leftBound, rightBound);
        quickSort(array, leftBound, part-1); //smaller part
        quickSort(array, part+1, rightBound); //larger part
   }   
}

//Look at implementing pre-increment instead of post increment for faster/efficient code

int partition(int *a, int left, int right){
    int pivot, i, k;
    pivot = left;
    i = left;
    k = right;

    while(i<=k && a[i]<=a[pivot]){
        while(i<=k && a[k]>=a[pivot]){
            k--;        
        }
        if(i<k){
            int swapV = a[i];
            a[i] = a[k];
            a[k] = swapV;
            i++, k--;
        }
       i++;
    } 
    if(a[k]<a[pivot]){
        int swapPiv = a[k];
        a[k] = a[pivot];
        a[pivot] = swapPiv;
        pivot = k;
        }
    return pivot; // The new pivot point
}
