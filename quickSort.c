#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * QuickSort algorithms.
 */

int quickSort(int *array, int leftBound, int rightBound);
int iterativequickSort(int *array, int leftBound, int rightBound);
int hquickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);
int hPartition(int *a, int left, int right);

bool correctness(int *array, int length);


int main(int argc, char* argv[]){
    srand(time(NULL));
    double timeE = 0.0;
    int C = 10000000; //10 Million element size will cause segment fault, over PC stack size. Stack size is default to 8MB, at 1M elements of ints is 4MB
    int N, R;
    
    for(R = 1, N = C; N >= 10;R *= 10, N /= 10){
        
        double totalTimeQ = 0.0;
        double totalTimeI = 0.0;
        double totalTimeH = 0.0;
        printf("-------------------------\n");
        printf("Amount of runs: %d\nNumber of elements: %d\n", R, N);
        printf("-------------------------");
        int hedgehogs[N]; //2.6MB at 650,000 -> 7.8MB for all 3
        int iterative[N];
        int hoa[N];
    

        for(int i = 0; i < R; i++){
             for(int s = 0; s<N; s++){
             hedgehogs[s] = rand();
             iterative[s] = rand();
             hoa[s] = rand();
         }
            clock_t start = clock();
            quickSort(hedgehogs, 0, N-1);
            clock_t end = clock();
            timeE = ((double)end-start)/CLOCKS_PER_SEC;
            totalTimeQ += timeE;
            start = clock();
            iterativequickSort(iterative, 0, N-1);
            end = clock();
            timeE = ((double)end-start)/CLOCKS_PER_SEC;
            totalTimeI += timeE;
            start = clock();
            hquickSort(hoa, 0, N-1);
            end = clock();
            timeE = ((double)end-start)/CLOCKS_PER_SEC;
            totalTimeH += timeE;
            
            if(correctness(hedgehogs, N) == false){
                printf("Is not correctly sorted during recursive\n");
                return 1;
            } else if (correctness(iterative, N) == false){
                printf("Is not correctly sorted during iterative\n");
                return 1;
            } else if(correctness(hoa, N) == false){
                printf("Is not correctly sorted during Hoare's\n");        
                return 1;
             }
        }
        printf("\ntotal time taken recursive: %f\n", totalTimeQ);
        printf("\ntotal time taken iterative: %f\n", totalTimeI);
        printf("\ntime taken hoa: %f\n", totalTimeH);
    }
    
    return 0;
}



/*
 * recursive quicksort function based on more so on David Power's and with Hoares pseudo code.
 */

int quickSort(int *array, int leftBound, int rightBound){
   
    if(leftBound < rightBound){

        int pivot = partition(array, leftBound, rightBound);
        if(leftBound < pivot){
            quickSort(array, leftBound, pivot-1);
            quickSort(array, pivot+1, rightBound);
        } else {
            quickSort(array, pivot+1, rightBound);
            quickSort(array, leftBound, pivot-1);
        }   
    }
    return *array;
}

int iterativequickSort(int *array, int leftBound, int rightBound){ 

    if(rightBound > leftBound){
        int stackP = 0;
        int logSize = ceil(((1+log(rightBound))/log(2)));
        int rBStack[logSize], lBStack[logSize];
        lBStack[++stackP] = leftBound, rBStack[stackP] = rightBound; //Push leftBound and rightBound into L/R stack respectively(number not element) and pre-increments stackP to 1 to start loop 
        
        while(stackP>0){
            leftBound = lBStack[stackP], rightBound = rBStack[stackP--]; //pop one from each stack
            if(rightBound>leftBound){ // if true isn't sorted, if false is sorted
                int p = partition(array, leftBound, rightBound);
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
    return *array;
}

int hquickSort(int *array, int leftBound, int rightBound){
    if(leftBound < rightBound){

        int pivot = hPartition(array, leftBound, rightBound);
        hquickSort(array, leftBound, pivot); //smaller part
        hquickSort(array, pivot+1, rightBound); //larger part
   }
    return *array;
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
        if (i <= k){
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
            --k, ++i;
        }
    }
    if (a[k] <= a[p]){
        int t = a[k];
        a[k] = a[p];
        a[p] = t;
        return k;
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

bool correctness(int *array, int size){
    
    for(int i = 0; i < size-1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
return true;
}
