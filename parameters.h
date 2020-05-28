#ifndef PARAMETERS_INCLUDED
#define PARAMETERS_INCLUDED

#define nl 20  // the lattice size is nl*nl


void start();
int *get_spins();
int **get_neib();
void generate_FLS_table(int **neib, int *spin);
int FLS_type(int **neib, int *spin, int i);
#endif

