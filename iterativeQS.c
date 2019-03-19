#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define SIZE 10

typedef struct{
    int *stack;
    int top;
    int maxSize;
}stackI;


void quickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);
void stackCreate(stackI *stack, int maxSize);
void stackDestroy(stackI *stack);
void stackPush(stackI *stack, int item);
void stackPop(stackI *stack);



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
      * Create temp array to hold 1+logN pairs of L+R bounds
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
    stackI stack; 
    stackCreate(&stack, (int)(log10(sizeof(&array)/sizeof(&array[0]))+1));
    if(leftBound < rightBound){
               
        int part = partition(array, leftBound, rightBound);
    /*    quickSort(array, leftBound, part-1); //smaller part
        quickSort(array, part+1, rightBound); //larger part
   
   */ }   
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

void stackCreate(stackI *stack, int maxSize){

    
}
