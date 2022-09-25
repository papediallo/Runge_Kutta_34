#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "k.h"





int main()
{



    printf("\n\nDans notre projet on considera le tableau  suivant \n\n\n");
    printf(" 0    | 0      0    0    0    | 0 \n");
    printf("2/7   | 2/7    0    0    0    | 0 \n");
    printf("4/7   |-8/35  4/5   0    0    | 0 \n");
    printf("6/7   | 29/42 -2/3  5/6  0    | 0 \n");
    printf("______|_______________________|___\n");
    printf("  1   | 1/6   1/6  5/12 1/4   | 0   \n");
    printf("______|_______________________|___   \n");
    printf("      | 11/96 7/24 35/96 7/48 | 1/12  \n\n\n");
    


	 
    //rk34(0,5,f,0.001,1,0.00001);
    printf("\n\n----------------\n\n");
    rk34(0,0.3333333,f,0.01,1,0.00001);



    //printf("la vraie solution \n\n");


    return 0 ;
}

