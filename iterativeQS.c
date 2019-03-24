#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define SIZE 10


void quickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);

int main(){
    int size = 0;
    srand(time(NULL));
    printf("How many elemets: ");
    scanf("%d", &size);
    int unSort[size];
    for(int s = 0; s < size; s++){
        unSort[s] = rand();
    } 
    int length = sizeof(unSort)/sizeof(unSort[0]);
    
    
    quickSort(unSort, 0, length-1);
    
    printf("now sorted\n");
    for(int i = 0; i<size;i++){
        printf("A[%d]: %d\n",i, unSort[i]);
    }    
    return 0;
}



void quickSort(int *array, int leftBound, int rightBound){ 
     /*
      * Create temp array/s to hold 1+logN pairs of L+R bounds
      *     - Push larger first
      *  
      *  Define bounds of array creating a subarray and push onto stack
      *     - avoid immediate pop after a push
      *     - two bounds to push/pop at a time
      *     - Remeber FILO
      *  
      *  While subarrays to pop 
      *     - if >2 elements, arrange as follows
      *         -choose one element as pivot
      *         - partition array into smaller and larger
      */
    int stackP = 0;
    int logN = log10(sizeof(&array)/sizeof(&array[0]));
    int rIndex[logN+1];
    int lIndex[logN+1];
    lIndex[++stackP] = leftBound, rIndex[stackP] = rightBound;
    
    while(stackP>0){
        if(rightBound-leftBound>1){
            int p = partition(array, leftBound, rightBound);

            if((rightBound-lIndex[stackP])<(leftBound-rIndex[stackP])){
                leftBound = lIndex[stackP], rightBound = rIndex[stackP--];
                lIndex[++stackP] = leftBound; rIndex[stackP] = p - 1;
                lIndex[++stackP] = p + 1; rIndex[stackP] = rightBound;
            } else { 
                rightBound = rIndex[stackP], leftBound = lIndex[stackP--];
                rIndex[++stackP] = rightBound, lIndex[stackP] = p - 1;
                rIndex[++stackP] = p + 1, lIndex[stackP] = leftBound;
            }
        
        } else { 
            break;
        }
    }
}
//Look at implementing pre-increment instead of post increment for faster/efficient code

int partition(int *a, int left, int right){
    int pivotE, i, k;
    pivotE = a[left];
    i = left-1, k = right+1;

    while(1){
        do{
         ++i;
     } while(a[i]<pivotE);
    do{
            --k;
        }while(a[k]>pivotE);
        if(i>=k){
            return k; //Return k as new pivot
        }
    int t = a[i];
    a[i] = a[k];
    a[k] = t;   //swap i and k
    } 
}




/*int partition(int *a, int left, int right){
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
}*/
