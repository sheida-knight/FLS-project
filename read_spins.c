#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "parameters.h"

int *get_spins(){

    int i;
    int *S = (int*)malloc((nl*nl)*sizeof(int*));

    FILE *read_spins;  // opening the data file to read the spins in the nl*nl lattice
    read_spins = fopen("data_file.txt","r");
    
    char temp;
    for (i=0; i<(nl*nl); i++)
    {
        fscanf(read_spins,"%d%c", &S[i], &temp);
    }
    
    fclose(read_spins);
    return S;
}
