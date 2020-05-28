#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "parameters.h"

void generate_FLS_table(int **neib, int *spin)
{
    FILE *output;  // create a file to write down FLS table in it
    output = fopen("./result/ML_input_data.csv","w");
    
    int i,j,k,f,d,n,l,nup,sp,z,longest,line, ndown, spd,type;
    double p1, p2, p3, p4, p5, p6, p7, p8;
    
    for (i=0; i<(nl*nl); i++)
       {
           type= FLS_type(neib,spin,i);
           fprintf(output,"%d ",type);
           
           if ( type ==-1) printf("ERROR! there is something wrong in calculating FLS type for site i");
           
           p1=p2=p3=p4=p5=p6=p7=p8=0.0;
           
           for (j=0; j<6; j++)
           {
               f=neib[i][j];   // evaluating the local environment around each neighbor (calculating the number of up spins around neighbors of site i)
               nup=0;
               sp=0;
               for (k=0; k<6; k++)  // looping over local environment around each neighbor of site i (f = neib[site i] and z=neib[neib[site i]]=neib[f])
               {
                   z=neib[f][k];
                   if (spin[z] > 0)
                   {
                       nup = nup+1;
                       sp = k;
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
                       l = neib[f][d];
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
                   p1 = p1 + (1.0/6.0);
    
               }
               else if ( nup == 1  || nup ==5)
               {
                   p2 = p2 + (1.0/6.0);
     
               }
               else // if nup <5
               {
                   if ( nup ==2 && longest ==2)
                   {
                       p3 = p3 + (1.0/6.0);

                   }
                   else if ( nup ==2 && longest ==3)
                   {
                       p4 = p4 + (1.0/6.0);
      
                   }
                   else if ( (nup ==2 && longest ==4)  || (nup ==4 && longest ==2))
                   {
                       p5 = p5 + (1.0/6.0);

                   }
                   else if ( nup ==3 && longest ==1)
                   {
                       p6 = p6 + (1.0/6.0);
              
                   }
                   else if ( nup ==3 && longest ==2)
                   {
                       p7 = p7 + (1.0/6.0);

                   }
                   else if (nup ==3 && longest ==3)
                   {
                       p8 = p8 + (1.0/6.0); // if (nup ==3 && longest ==3)
               
                   }
                   else if  (nup ==4 && longest ==1)
                   {
                       ndown=0;
                       spd=0;
                       for (k=0; k<6; k++)  // looping over local environment around each neighbor of site i (f = neib[site i] and z=neib[neib[site i]]=neib[f])
                       {
                           z=neib[f][k];
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
                           l = neib[f][d];
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
                           p3 = p3 + (1.0/6.0);

                       }
                       else // ( longest == 3)
                       {
                           p4 = p4 + (1.0/6.0);
                
                       }
                                    
                   }
               
               }  // if nup <5
               
           }   // loop around 6 neighbors of each site
           
           
           //printf("p1 = %f  p2=%f  p3=%f  p4=%f  p5=%f  p6=%f  p7=%f  p8=%f \n",p1,p2,p3,p4,p5,p6,p7,p8);
           fprintf(output,"%f,%f,%f,%f,%f,%f,%f,%f,N\n",p1,p2,p3,p4,p5,p6,p7,p8);
               
       }   // loop around all the (nl*nl) sites
}



