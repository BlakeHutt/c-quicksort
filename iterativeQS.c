#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

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
    
    if(rightBound > leftBound){
        int stackP = 0;
        //int logN = log10(sizeof(array)/sizeof(&array[0]));
        int rBStack[10], lBStack[10];
        lBStack[++stackP] = leftBound, rBStack[stackP] = rightBound; //Store leftBound and rightBound into L/R stack respectively(number not element) and pre-increments stackP to 1 to start loop 
        
        while(stackP>0){
            leftBound = lBStack[stackP], rightBound = rBStack[stackP--]; //pop stack
            if(rightBound-leftBound>1){
                int p = partition(array, leftBound, rightBound);
                int lP = p+1, rP = p-1;

                if((rightBound-lP)<(leftBound-rP)){// rightside is larger (Is right side larger than left side?)
                    lBStack[++stackP] = lP, rBStack[stackP] = rightBound; // push large
                    lBStack[++stackP]=  leftBound, rBStack[stackP] = rP; // push small
                 } else {//rightside is smaller
                    lBStack[++stackP] = leftBound, rBStack[stackP] = rP; // push large
                    lBStack[++stackP] = lP, rBStack[stackP] = rightBound; // push small
                 }               
            } else {
                --stackP;
            }
         }
    }
}

/*Look at implementing pre-increment instead of post increment for faster/efficient code
 *  Based off of Hoares partition scheme
 */

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
    a[k] = t;
    } 
}
