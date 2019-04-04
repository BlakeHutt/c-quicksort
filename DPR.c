#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

/* 
 * Recursive QuickSort.
 */

void quickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);
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
    quickSort(hedgehogs, 0, size);
    clock_t end = clock();

    timeE=((double)end-start)/CLOCKS_PER_SEC;

    for(int p =0; p<size;p++){
        printf("A[%d]: %d\n", p, hedgehogs[p]);
        if(hedgehogs[p] > hedgehogs[p+1]&& p+1<size){
            return 1;
        }
    }
    printf("time elapsed: %f\n", timeE);
    return 0;
}
/*
 * Quicksort funciton based on more so on David Power's and with Hoares pseudo code.
 */
void quickSort(int *array, int leftBound, int rightBound){
   
    if(leftBound < rightBound){

        int pivot = partition(array, leftBound, rightBound);
            quickSort(array, leftBound, pivot-1);
            quickSort(array, pivot+1, rightBound);
        }   
    
}


/*
 * Partition Scheme based on David Power's partition pseudo code
 */

int partition(int *a, int left, int right){
    int p, i, k;
    p = left, i = ++left, k = right;

    while(i<=k){
        while(i<=k && a[i] <= a[p]){
            ++i;
        }
        while(i<=k && a[k] >= a[p]){
            --k;
        }
        if (i < k){
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
    if (a[k] < a[p]){
        int t = a[k];
        a[k] = a[p];
        a[p] = t;
        p = k;
    }
    return p;
}
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
