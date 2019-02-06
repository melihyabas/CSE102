/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>
#include "hw4_io.h"
#include "hw4_lib.h"


/*
** Testing derivative calculations..
**
*/  

void test_compare_derivatives()
{
	double f(double x) { return x*x; } /*This function tests the error in numeric calculation of derivatives vs. actual derivatives given by functions d1 and d2. */
	double d1(double x) { return 2.0*x; }
	double d2(double x) { return 2.0; }
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 10.0, 0.0001, &e1, &e2);
	printf("%lf %lf\n",e1,e2);
} 

void test_integral()
{
	double f(double x) { return x*x; }
	printf("%lf", integral(f, 0, 2, 0.0001)); /*This function calculetes integral of f function 0 to 2. (0.0001 is delta)   */

} 

void test_integral2()
{
	double f(double x, double y) { return x*x+y*y+2; }
	printf("%lf", integral2(f, 0, 2, 0, 2, 0.001));
} 

void test_derivatives()
{
	double f(double x) { return x*x; }
	double d1,d2;
	int res = derivatives(f, 3, 0.00001, & d1, & d2); /*This function calculates first and second derivative of f function on 3. (0.00001 is delta)  */
	if(res!=0)
		printf("d1:  %lf d2:  %lf",d1,d2);
} 

void test_find_roots()
{	/*This function finds the real root of the f function returning the number of roots found and the roots in the arguments x1, x2, x3 and x4. */
	double f(double x) { return x*x-16; }
	double x1, x2, x3, x4;
	find_roots( f, &x1, &x2, &x3, &x4);
	printf("x1:%lf  x2:%lf  x3:%lf  x4:%lf",x1,x2,x3,x4);
	
	
} 

/*
** main function for testing the functions...
**
*/
int main(void)
{

	double a0, a1, a2 ,a3, a4;
	
/*You can use the following functions to test the written programs.*/	
	
/*	write_polynomial4(a0, a1, a2, a3, a4);  */
/*	write_polynomial3(a0, a1, a2, a3);  */

/*	test_integral(); */
/*	test_integral2(); */
/*	test_derivatives(); */
/*	test_compare_derivatives();	*/
/*  test_find_roots(); */
	
	return (0);
} /* end main */
