#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

#define SWP(x, y) (x^=y y^=x x^=y)
/* 
 * Recursive QuickSort algorithm based on the psuedo code found on wikipedia of Hoare's partition Scheme.
 *
 */
void quickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);

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
    quickSort(hedgehogs, 0, length-1);
    clock_t end = clock();

    timeE=((double)end-start)/CLOCKS_PER_SEC;

    for(int p =0; p<size;p++){
        printf("A[%d]: %d\n", p, hedgehogs[p]);
    }
    printf("time elapsed: %f\n", timeE);
    return 0;
}

void quickSort(int *array, int leftBound, int rightBound){
    if(leftBound < rightBound){

        int pivot = partition(array, leftBound, rightBound);
        quickSort(array, leftBound, pivot); //smaller part
        quickSort(array, pivot+1, rightBound); //larger part
   }   
}

//Look at implementing pre-increment instead of post increment for faster/efficient code

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
        //SWP(a[i], a[k]);
    int t = a[i];
    a[i] = a[k];
    a[k] = t;   //swap i and k
    } 
}
