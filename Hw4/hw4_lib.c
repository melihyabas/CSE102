/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"

double integral(double f (double x),double xs, double xe, double delta)	
{
	int i;
	double total=0;	/*This function makes a numeric calculation of the integral of the function f within the range [xs,xe]. The given parameter delta provides the step size for the integration.*/
	for(i=1 ; i<=(xe-xs)/delta ; i++)
	{
		total+=delta*f(xs+i*delta);
	}
		
	return total;
}

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta)
{	/*This function makes a numeric calculation of the integral of a two input function within the given range [xs,xe] and [ys,ye]. */
	int i,j;
	double total=0;
	for(i=1 ; i<=(xe-xs)/delta ; i++)
	{
		for(j=1 ; j<=(ye-ys)/delta ; j++)
			total += delta*delta*f(xs+i*delta,ys+j*delta);
	}
	return total;	
}

int derivatives(double f (double x),double x, double eps, double * d1, double * d2)
{	/*This function makes a numeric calculation of first (d1) and second (d2) derivative of a given function*/
	if(eps==0)
		return 0;	
	*d1= (f(x+eps)-f(x-eps))/(2*eps);
	*d2 = (f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);
	return 1;
}

int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2)
{
	/*This function tests the error in numeric calculation of derivatives vs. actual derivatives given by functions d1 and d2.*/
	derivatives(f, x, eps,  &*e1, &*e2);	

		*e1 -= d1(x);
  		*e2 -= d2(x);

	return 0;
	
}


int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4)
{
	double i;
	int j=0;
	double array[5];
/*This function finds the real root of the function returning the number of roots found and the roots in the
arguments x1, x2, x3 and x4.*/	
	for(i=-10000 ; i<10000 ; i++)
	{
		if(f(i)==0)
		{
			array[j]=i;
			j++;
		}
	}
	*x1=array[0];
	*x2=array[1];
	*x3=array[2];
	*x4=array[3];
	
	return 0;
}
