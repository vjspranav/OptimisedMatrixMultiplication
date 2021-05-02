# Assignment 2
# OptimisedMatrixMultiplication

## Improvements/Optimisations
* My inital code had segmentaation faults and hence I had to rework the entire code.
* I started by using a Structure to store matrices.
* Used register ints wherever I had iterations
* Used OpenMP to parrelilze loops, especially the outermost loop of Matrix multiplication
* Changed the order of loops, so that I have less cache misses.
* Avoided loop unrolling, as O2 optimisation handles that.
* Using pre increment over post increment (++i/i++)
Compiled usinfg
```
gcc -fopenmp -O2 q1.c -march=native
```

## Performance
### Cachegrind
![image](https://user-images.githubusercontent.com/17949836/116821105-2474a380-ab96-11eb-870e-991f9c91d17f.png)  
Shows the number of cache misses

### gprof
![image](https://user-images.githubusercontent.com/17949836/116821469-98fc1200-ab97-11eb-9348-552c2984c476.png)  
Show the time taken by matmult function

### Time taken
![image](https://user-images.githubusercontent.com/17949836/116821553-f6905e80-ab97-11eb-84cf-ca879773fe18.png)  
Time taken to run 

### Perf
**Record**
![image](https://user-images.githubusercontent.com/17949836/116821640-4a9b4300-ab98-11eb-9bba-1a84563763b0.png)
![image](https://user-images.githubusercontent.com/17949836/116821655-5dae1300-ab98-11eb-8e0b-04898be91791.png)
* Shows us how the operations occur at assembly level
* Any data that missed, any that took longer to be accessed

**Stat**
![image](https://user-images.githubusercontent.com/17949836/116821704-8c2bee00-ab98-11eb-9c5b-6a334ae419ba.png)


