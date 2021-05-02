# Assignment 2
# OptimisedMatrixMultiplication

## Improvements
* My inital code had segmentaation faults and hence I had to rework the entire code.
* I started by using a Structure to store matrices.
* Used register ints wherever I had iterations
* Used OpenMP to parrelilze loops, especially the outermost loop of Matrix multiplication
* Changed the order of loops, so that I have less cache misses.
* Avoided loop unrolling, as O2 optimisation handles that.
* Using pre increment over post increment
Compiled usinfg
```
gcc -fopenmp -O2 q1.c -march=native
```

## Optimisatoins
