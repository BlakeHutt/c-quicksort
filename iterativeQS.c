#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void iterativequickSort(int *array, int leftBound, int rightBound);
int parti(int *a, int left, int right);

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
    
    clock_t start = clock();
    iterativequickSort(unSort, 0, length-1);
    clock_t end = clock();
    
    double timeE = ((double)end-start)/CLOCKS_PER_SEC;
   // printf("now sorted\n");
    for(int i = 0; i<size;i++){
 //       printf("A[%d]: %d\n",i, unSort[i]);
        if(unSort[i] > unSort[i+1]&& i+1<size){
               return 1;
    }
    }
    printf("%f\n", timeE);
    return 0;

}



void iterativequickSort(int *array, int leftBound, int rightBound){ 

    if(rightBound > leftBound){
        int stackP = 0;
        int logSize = ceil(((1+log(rightBound))/log(2)));
        int rBStack[logSize], lBStack[logSize];
        lBStack[++stackP] = leftBound, rBStack[stackP] = rightBound; //Push leftBound and rightBound into L/R stack respectively(number not element) and pre-increments stackP to 1 to start loop 
        
        while(stackP>0){
            leftBound = lBStack[stackP], rightBound = rBStack[stackP--]; //pop one from each stack
            if(rightBound>leftBound){ // if true isn't sorted, if false is sorted
                int p = parti(array, leftBound, rightBound);
                int lPnt = p+1, rPnt = p-1;
                
                if(p - leftBound < rightBound - p){
                    if(lPnt < rightBound){
                        lBStack[++stackP] = lPnt, rBStack[stackP] = rightBound;
                    }
                    if (leftBound < rPnt){
                        lBStack[++stackP] = leftBound, rBStack[stackP] = rPnt;
                    }
                } else {
                    if(leftBound < rPnt){
                        lBStack[++stackP] = leftBound, rBStack[stackP] = rPnt;
                    }
                    if(lPnt < rightBound){
                        lBStack[++stackP] = lPnt, rBStack[stackP] = rightBound;
                    }
                }
            }       
        }
    }
}

/*
 *Partition code based on David Powers psuedo code
 *
 */

int parti(int *a, int left, int right){
    int i, j, pivot = left;
    i = left+1, j = right;
    while(i<=j){
        while(i <= j && a[i] <= a[pivot]){
           ++i;
        } 
        while(i <= j && a[j] >= a[pivot]){
            --j;
        }
        if (i<=j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++i, --j;
        }
    }
    if(a[j] <= a[pivot]){
    int t = a[j];
    a[j] = a[pivot];
    a[pivot] = t;
    return j;
}
return pivot;
}


