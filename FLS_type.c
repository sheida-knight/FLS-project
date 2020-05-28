#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "parameters.h"

int FLS_type(int **neib, int *spin, int i)
{
    
    int j,k,f,d,n,l,nup,sp,z,longest,line, ndown, spd, type=-1;
    nup=0;
    sp=0;
    
    
    for (j=0; j<6; j++)
    {
        f=neib[i][j];      // evaluating the local environment around given site i
        if (spin[f] > 0)
        {
            nup = nup+1;
            sp = j;
        }
    }
    
    longest=0;
    line=0;
    d=sp;   // the index of last neighbor with spin up
    
    
    if (nup == 6) longest = 0;
    
    else if (nup == 5) longest =1;
    
    else  // if nup <5
    {
        for (n=0; n<5; n++)  // looping over the reminding 5 neighbors (d=sp is one with up spin) to count the longest line of spin downs
        {
            d=d+1; if (d>5) d = d-6;;
            l = neib[i][d];
            if (spin[l] < 0 )
            {
                line = line+1;
                if (line > longest) longest = line;
            }
            else
            {
                line = 0;
            }
        }
    }
    
    if ( nup == 0 || nup == 6)
               {
                   type=1;
               }
               else if ( nup == 1  || nup ==5)
               {
                   type = 2;
               }
               else // if nup <5
               {
                   if ( nup ==2 && longest ==2)
                   {
                       type = 3;
                   }
                   else if ( nup ==2 && longest ==3)
                   {
                        type = 4;
                   }
                   else if ( (nup ==2 && longest ==4)  || (nup ==4 && longest ==2))
                   {
                       type = 5;
                   }
                   else if ( nup ==3 && longest ==1)
                   {
                       type = 6;
                   }
                   else if ( nup ==3 && longest ==2)
                   {
                       type = 7;
                   }
                   else if (nup ==3 && longest ==3)
                   {
                       type = 8;
                   }
                   else if  (nup ==4 && longest ==1)
                   {
                       ndown=0;
                       spd=0;
                       for (k=0; k<6; k++)  // looping over local environment around each neighbor of site i (f = neib[site i] and z=neib[neib[site i]]=neib[f])
                       {
                           z=neib[i][k];
                           if (spin[z] < 0)
                           {
                               ndown = ndown+1;
                               spd = k;
                           }
                       }
                       longest=0;
                       line=0;
                       d=spd;   // the index of last neighbor with spin down
                   
                       for (n=0; n<5; n++)  // looping over the reminding 5 neighbors (d=sp is one with up spin) to count the longest line of spin downs
                       {
                           d=d+1; if (d>5) d = d-6;;
                           l = neib[i][d];
                           if (spin[l] > 0 )
                           {
                               line = line+1;
                               if (line > longest) longest = line;
                           }
                           else
                           {
                               line = 0;
                           }
                       }
                   
                       if ( longest == 2)
                       {
                           type = 3;
                       }
                       else // ( longest == 3)
                       {
                           type = 4;
                       }
                   
                   
                   }
               
               
               }  // if nup <5
    
    return type;
    
}
