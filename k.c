#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "k.h"

#define TAILLE 20


typedef double tab[100000];


// True solution 
double g(double a)
{
    double b;
    b= (1/(2*a+3));
    //b = 5*exp(-pow(a,3)-a);
    //b = asin(-log(abs(cos(a))));
    return b;
}


// fonction pour caluler la fonction y'(x)
double f(double a, double b)
{
    double m;
    m = ( -2*pow(b,2) + a*(2*a+3)*b -a ) ;
    //m = -(3*pow(a,2) + 1)*b;
    //m = (tan(a)/cos(b));
    return m;
}



// return le max entre ces deux nbres
double max(double a, double b)
{
    if(a<b) return b;
    else return a;
}



// pour implementer la methode RK34
void rk34(double to,double yo, double f(double,double) ,double h, double T,double tol)
{
    // les tableaux pour stocker les to , la solution excate , la solution approche 
    // pour faciliter la comparaison
    tab t,y,z,k34,er;

    // évaluations de dérivées
    double k1,k2,k3,k4,y1,y2;

    // declarartion et initialisation de l'erreur
    double err;


    // pour l'erreur
    double sci =0;


    // pour le nbre d'iteration de la methode
    int i=0;
    
    // pour copier le pas de départ
    double p=h;

    while( to <= T )
    {
	
	
	// les differentes valeurs des k
        k1 = f(to,yo);
        k2 = f( to + 2*h/7 , yo + (h/7)*(2*k1 ));
        k3 = f( to + 4*h/7 , yo + ( h/35 )*( -8*k1 + 28*k2 ) );
        k4 = f( to + 6*h/7 , yo + ( h/42 )*( 29*k1 - 28*k2 + 35*k3 ) );

	// la valeur de y pour RK34
        y1= yo + ( h/12 )*( 2*k1 + 2*k2 + 5*k3 + 3*k4 );
	
	// la valeur pour le RK3
        y2= yo + ( h/96)*( 11*k1 + 28*k2 + 35*k3 + 14*k4 + 8*f(to + h, y1) );



        // pour les differentes valeurs de to
        t[i]=to;

        // pour la solution excate
        z[i]= g(to);

        // la valeur de RK34
        y[i]=y1;

        // la valeur de RK3
        k34[i]=y2;

        
        
        // Pour l'erreur
        
        err= (y1-y2);
        
        // Pour stocker l'erreur
        er[i]=err;

	// pour voir si on doit changer le "pas"  ou pas
        if(err > tol)  h = h*0.5;
        
        // incrementation de to et i
        to=to+h;
        

        //
        yo=y1;
        
        // pour nous donner le nbre d'iteration
        i++;

    }

    int n=i;


    
   
    printf("\n\n");
    printf(" t              RK34             RK3            True sol            erreur \n\n");
    for(int k=0;k<n;k+=10)
    {
        printf(" %lf         %lf       %lf       %lf       %lf\n",t[k],y[k],k34[k],z[k],er[k]);
    }


    printf("\n\n\nl'erreur est %lf\n",err);
    
    printf("\n\n\nle pas est %lf\n",h);

    if(h==p)
    {
        printf("\n\n\nle pas est accepté\n\n\n");
    }
    else printf("\n\n\nle pas de départ (%lf) n'est pas accepté\n",p);


}



