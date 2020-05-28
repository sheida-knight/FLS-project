#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "parameters.h"


// we have defined 6 neighbors on clockwise order around each site i in a honeycomb lattice
int **get_neib()
{
    int i, x, y, px, py;

    int **neib=(int**)malloc((nl*nl)*sizeof(int*));
    for (i=0;i<nl*nl;i++) neib[i] = (int *)malloc((6) * sizeof(int));
    
    for (i=0; i<(nl*nl); i++)
    {
        x= i% nl;     // converting each site location  to a 2D lattice and calculating the neigbors using 2D lattice rules
        y= i/nl;
        
        if ( (i/nl) % 2 == 0)  // // choosing the even row numbers in the lattice
        {
            px = x;
            py = y-1; if (py<0) py = py+nl;
            neib[i][0] = px+(py*nl);
            
            px = (x+1)% nl;
            py = y;
            neib[i][1] = px+(py*nl);
            
            px = x;
            py = (y+1)%nl;
            neib[i][2] = px+(py*nl);
            
            px = x-1; if (px<0) px = px+nl;
            py = (y+1)%nl;
            neib[i][3] = px+(py*nl);
            
            px = x-1; if (px<0) px = px+nl;
            py = y;
            neib[i][4] = px+(py*nl);
            
            px = x-1; if (px<0) px = px+nl;
            py = y-1; if (py<0) py = py+nl;
            neib[i][5] = px+(py*nl);
        }
        else    // if ( (i/nl) % 2 != 0)  // choosing the odd rows in the lattice
        {
            px = (x+1)%nl;
            py = y-1; if (py<0) py=py+nl;
            neib[i][0] = px+(py*nl);
            
            px = (x+1)%nl;
            py = y;
            neib[i][1] = px+(py*nl);
            
            px = (x+1)%nl;
            py = (y+1)%nl;
            neib[i][2] = px+(py*nl);
            
            px = x;
            py = (y+1)%nl;
            neib[i][3] = px+(py*nl);
            
            px = x-1; if (px<0) px = px+nl;
            py = y;
            neib[i][4] = px+(py*nl);
            
            px = x;
            py = y-1; if (py<0) py = py+nl;
            neib[i][5] = px+(py*nl);
            
        }
    }
    
    return (neib);
    
}
