#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "parameters.h"

void start(){
    
    int i;
    
    
    int *spin = (int*)malloc((nl*nl)*sizeof(int*));  // defining a 1D array of size (nl*nl) to store the spins for each site for the lattice
    spin=get_spins();  // Calling the function to read the input file
    
    int **neib=(int**)malloc((nl*nl)*sizeof(int*));
    for (i=0;i<nl*nl;i++) neib[i] = (int *)malloc((6) * sizeof(int));
    neib=get_neib();
    
    generate_FLS_table(neib,spin);
    

}
