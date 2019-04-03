# quicksort 

Repo containing both a version of iterative and recursive quicksort in C.
Makefile contains a build and clean operation to create each file executable and to remove them if necessary.
    -make build and make clean respectively


DPR is based on David Power's pseudo code found on the assignment 1 spec in a recursive fashion

Recursive quicksort(recursiveQS) is based on Hoare's partition scheme found on Wikipedia.

Iterative quicksort(iterativeQS) is based on the pseudo code given by David Powers for assignment 1. With stack implementation with arrays.

The file quickSort is a culmination of all three algorithms in one file and runs with the default value of 650,000 sized arrays.
    - Because of the soft default stack of 8MB in most computers per process, having 3 arrays for each sort limits the max size of 650,000, resulting in a 7.8MB stack. 
    - If you were to increase the stack size, via ulimit -s in a unix and/or linux environment, you can increase the stack size of processes ie 10240kB for a 10MB stack
        - The above stack size of 10240kB would allow the three arrays to reach a max size of 800,000 for all three arrays.

