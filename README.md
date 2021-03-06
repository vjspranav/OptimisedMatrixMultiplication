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
* As memory limitation was not given, we focused on speed and let the memory be used.
* Tried to improve on some single core optimisations which I could not gain.  

## To Compile
Compiled using
```
gcc -fopenmp -O2 q1.c -march=native
```


## Comparisions
As my single core optimisations were not good, I don't have proper data to compare to  
* I could notice an improvent of 10-15 seconds on a set of 1000*1000 matrices completely unoptimised vs parallel optimised  

## Performance
### Cachegrind
![image](https://user-images.githubusercontent.com/17949836/116821105-2474a380-ab96-11eb-870e-991f9c91d17f.png)  
Shows the number of cache misses

### gprof
* Before Parallelisation  
![image](https://user-images.githubusercontent.com/17949836/116822660-9dc3c480-ab9d-11eb-959b-67ea4f35b7c5.png)
* After Parallelisation  
![image](https://user-images.githubusercontent.com/17949836/116821469-98fc1200-ab97-11eb-9348-552c2984c476.png)  

Show the time taken by matmult function

### Time taken
* Before Parallelisation  
![image](https://user-images.githubusercontent.com/17949836/116822626-6ce38f80-ab9d-11eb-924d-78c0b3e3981a.png)  
* After Parallelisation  
![image](https://user-images.githubusercontent.com/17949836/116821553-f6905e80-ab97-11eb-84cf-ca879773fe18.png)  

Time taken to run 

### Perf  
**Record**  
![image](https://user-images.githubusercontent.com/17949836/116821640-4a9b4300-ab98-11eb-9bba-1a84563763b0.png)
![image](https://user-images.githubusercontent.com/17949836/116821655-5dae1300-ab98-11eb-8e0b-04898be91791.png)
* Shows us how the operations occur at assembly level
* Any data that missed, any that took longer to be accessed  

**Stat**  
* Before Parallelisation   
![image](https://user-images.githubusercontent.com/17949836/116822686-d8c5f800-ab9d-11eb-984c-ee8a480a6030.png)
* After Parallelisation  
![image](https://user-images.githubusercontent.com/17949836/116821704-8c2bee00-ab98-11eb-9c5b-6a334ae419ba.png)

We can here clearly see how huge of a difference parallelisation can make in CPU Utilisation and time taken to run 

