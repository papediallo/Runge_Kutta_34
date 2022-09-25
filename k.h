#ifndef  __K_H__
#define  __K_H__

#define TAILLE 20


typedef double tab[100000];

// true solution
double g(double a);

// fonction pour caluler la fonction y'(x)
double f(double a, double b);


// return le max entre ces deux nbres
double max(double a, double b);


// la fonction pour le calcul de RK34
void rk34(double to,double yo, double f(double,double) ,double h, double T,double tol);




//donnees utilisees
//pour f(x,y)=m=-(3*pow(a,2) + 1)*b

//rk34(0,5,f,0.01,1,0.00001);
//rk34(0,5,f,0.01,1,0.000001)

//rk34(0,5,f,0.001,1,0.00001);
//rk34(0,5,f,0.001,1,0.000001);

//rk34(0,5,f,0.1,1,0.00001);
//rk34(0,5,f,0.1,1,0.000001);


// pour f(x,y)=m = ( -2*pow(b,2) + a*(2*a+3)*b -a ) 

//rk34(0,0.333333,f,0.01,1,0.00001);
//rk34(0,0.333333,f,0.01,1,0.000001);

//rk34(0,0.333333,f,0.001,1,0.00001);
//rk34(0,0.333333,f,0.001,1,0.000001);
//rk34(0,0.333333,f,0.001,1,0.0000000001);

//rk34(0,0.333333,f,0.1,1,0.000001);
//rk34(0,0.333333,f,0.1,1,0.00000001);


// pour f(x,y)=m = (tan(a)/cos(b))

//
//

//
//

//
//





#endif
