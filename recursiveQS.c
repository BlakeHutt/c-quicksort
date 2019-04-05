#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

/* 
 * Recursive QuickSort algorithm based on the psuedo code found on wikipedia of Hoare's partition Scheme.
 *
 */
void hquickSort(int *array, int leftBound, int rightBound);
int hPartition(int *a, int left, int right);

int main(int argc, char* argv[]){
    srand(time(NULL));
    double timeE = 0.0;
    int size = 0;
    printf("enter how many: ");
    scanf("%d", &size);
    int hedgehogs[size];

    for(int s = 0; s < size; s++){
        hedgehogs[s] = rand();
    }
    int length = sizeof(hedgehogs)/sizeof(hedgehogs[0]);
    
    clock_t start = clock();
    hquickSort(hedgehogs, 0, length-1);
    clock_t end = clock();

    timeE=((double)end-start)/CLOCKS_PER_SEC;

    for(int i =0; i<size;i++){
      //  printf("A[%d]: %d\n", p, hedgehogs[p]);
      if(hedgehogs[i] > hedgehogs[i+1]&& i+1<size){
             printf("failed\n");
             printf("%d: %d with %d: %d\n", i, hedgehogs[i], i+1, hedgehogs[i+1]);
             return 1;
        }
    }
    printf("time elapsed: %f\n", timeE);
    return 0;
}


void hquickSort(int *array, int leftBound, int rightBound){
    if(leftBound < rightBound){

        int pivot = hPartition(array, leftBound, rightBound);
        hquickSort(array, leftBound, pivot); //smaller part
        hquickSort(array, pivot+1, rightBound); //larger part
   }   
}

//Look at implementing pre-increment instead of post increment for faster/efficient code

int hPartition(int *a, int left, int right){
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
    a[k] = t;   //swap i and k
    } 
}
