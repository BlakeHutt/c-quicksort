#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * QuickSort algorithms.
 */

void quickSort(int *array, int leftBound, int rightBound);
void iterativequickSort(int *array, int leftBound, int rightBound);
void hquickSort(int *array, int leftBound, int rightBound);
int partition(int *a, int left, int right);
int hPartition(int *a, int left, int right);

bool correctness(int *array, int length, int *dupes);


int main(int argc, char* argv[]){
    srand(time(NULL));
    double timeE = 0.0;
/*    int size = 0;
    printf("enter how many: ");
    scanf("%d", &size);
    int hedgehogs[size];
    */
    int C = 500000; //10 Million element size will cause segment fault, over PC stack size.
    int N, R;
   // int k = ceil(log(C)/log(2));
    
    for(R = 1, N = C; N >= 10;R *= 10, N /= 5){
        double totalTimeQ = 0.0;
        double totalTimeI = 0.0;
        double totalTimeH = 0.0;
        printf("-------------------------\n");
        printf("Amount of runs: %d\nNumber of elements: %d\n", R, N);
        printf("-------------------------");
        int hedgehogs[N];
        int iterative[N];
        int hoa[N];
        int dupes = 0;
        //clock_t start = clock();
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
            if(correctness(hedgehogs, N, &dupes) == false || correctness(iterative, N, &dupes) == false){
                printf("Is not correctly sorted on%d\n", N);
                return 1;
             } 
        }
       // clock_t end = clock();
       // timeE=((double)end-start)/CLOCKS_PER_SEC;
        printf("\ntotal time taken recursive: %f\nnumber of runs: %d\n", totalTimeQ, R);
        printf("\ntotal time taken iterative: %f\nnumber of runs: %d\n", totalTimeI, R);
        printf("\ntime taken hoa: %f\nnumber of runs: %d\n", totalTimeH, R);
    }
/*    for(int s = 0; s < size; s++){
        hedgehogs[s] = rand();
    }
    int length = sizeof(hedgehogs)/sizeof(hedgehogs[0]);
   */ 
    //clock_t start = clock();
    //quickSort(hedgehogs, 0, length-1);
    //clock_t end = clock();

    //timeE=((double)end-start)/CLOCKS_PER_SEC;
    //int dupes = 0;
   /* if(correctness(hedgehogs, size, &dupes) == false){
        printf("Is not correctly sorted\n");
        return 1;
    }*/  
    //printf("time elapsed: %f\nnumer of dupes: %d", timeE, dupes);
    return 0;
}



/*
 * Quicksort funciton based on more so on David Power's and with Hoares pseudo code.
 */

void quickSort(int *array, int leftBound, int rightBound){
   
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
}

void iterativequickSort(int *array, int leftBound, int rightBound){ 

    if(rightBound > leftBound){
        int stackP = 0;
        int aSize = sizeof(array)/sizeof(&array[0]);
        int logSize = ceil(((1+log(aSize))/log(2)));
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
}

void hquickSort(int *array, int leftBound, int rightBound){
    if(leftBound < rightBound){

        int pivot = hPartition(array, leftBound, rightBound);
        hquickSort(array, leftBound, pivot); //smaller part
        hquickSort(array, pivot+1, rightBound); //larger part
   }
}



/*
 * Partition Scheme based on David Power's partition pseudo code
 */

int partition(int *a, int left, int right){
    int p, i, k;
    p = (left), i = ++left, k = right;

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

bool correctness(int *array, int size, int *dupes){
    
    for(int i = 0; i < size-1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
        if(array[i] == array[i+1]){
            dupes+=1; 
        }
        return true;
    }

}
