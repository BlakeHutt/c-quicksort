#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define swp(x,y) {x^=y;y^=x;x^=y;}

void quickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);
int part(int *a, int left, int right);
int part2(int *a, int left, int right);

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
        int rBStack[50], lBStack[50];
        lBStack[++stackP] = leftBound, rBStack[stackP] = rightBound; //Push leftBound and rightBound into L/R stack respectively(number not element) and pre-increments stackP to 1 to start loop 
        
        while(stackP>0){
            leftBound = lBStack[stackP], rightBound = rBStack[stackP--]; //pop one from each stack
            if(rightBound>leftBound){ // if true isn't sorted, if false is sorted
                int p = part(array, leftBound, rightBound);
                int lP = p+1, rP = p-1;

                if((rightBound-lP)<(leftBound-rP)){// rightside is larger (Is right side larger than left side?)
                    lBStack[++stackP] = lP, rBStack[stackP] = rightBound; // push large
                    lBStack[++stackP]=  leftBound, rBStack[stackP] = rP; // push small
                 } else {//rightside is smaller
                    lBStack[++stackP] = leftBound, rBStack[stackP] = rP; // push large
                    lBStack[++stackP] = lP, rBStack[stackP] = rightBound; // push small
                 }               
            } else{ //Is already sorted
               --stackP;
            }
         }
    }
}

/*
 * Look at implementing pre-increment instead of post increment for faster/efficient code
 *  Based off of Hoares partition scheme
 */

int partition(int *a, int left, int right){
    int pivotE, i, k;
    pivotE = a[(left+right)/2];
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

/*
 *Partition code based on David Powers psuedo code
 *
 */

int part(int *a, int left, int right){
    int i, j, pivot = left;
    i = left+1, j = right;
    int count = 0, swap = 0;
    while(i<=j){
        count++;
        while(i <= j && a[i] <= a[pivot]){
            ++i;
        } 
        while(i <= j && a[j] >= a[pivot]){
            --j;
        }
        if (i<j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            printf("swaped to i: %d, j: %d\n", i, j);
            i++, j--, swap++;
        }
    }
    printf("%d i, %d, j, %d piv, %d count, %d swaps\n", i, j, pivot, count, swap);
    printf("%d aPiv, %d aJ\n", a[pivot], a[j]);
  if (a[j] < a[pivot]){
        int t = a[j];
        a[j] = a[pivot];
        a[pivot] = t;
        pivot = j;
    }  
return pivot;
}


int part2(int *a, int left, int right){

    int piv = a[right];
    int k = left -1;

    for(int j = left; j <= right-1; j++){
        if(a[j] <= piv){
            k++;
            int t = a[j];
            a[j] = a[k];
            a[k] = t;
        }
    }
    int t = a[k+1];
    a[k+1] = a[right];
    a[right] = t;
    return  k+1;
}
