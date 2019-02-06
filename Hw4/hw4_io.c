/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"

int read_polynomial3(double * a0, double * a1, double * a2, double * a3)
{
	printf("Please enter coefficients:"); /*Polynomial coefficients were taken from the user.*/
	scanf("%lf %lf %lf %lf", a0, a1, a2, a3);	
	
	return 0;
}

int read_polynomial4(double * a4, double * a3, double * a2, double * a1, double * a0)
{
	printf("Please enter coefficients:");	/*Polynomial coefficients were taken from the user.*/
	scanf("%lf%lf%lf%lf%lf", a4, a3, a2, a1, a0);

	return 0;	
}

void write_polynomial3(double a0, double a1, double a2, double a3)
{
	read_polynomial3(&a3, &a2, &a1, &a0);
	if(a3!=1&&a3!=-1&&a3!=0)
		printf("%gx^3",a3);		/*This function writes the polynomial in a pretty format.*/
	if(a3==1)
		printf("x^3");		/*The coefficients were checked for positive, negative and zero. (For the all coefficients.)*/
	if(a3==-1)
		printf("-x^3");
	if(a2!=1&&a2!=-1&&a2!=0)
	{	
		if(a2>0)
		{								/*This operations were done for a third-order polynomial.*/
			if(a3!=0&&a2!=0)
				printf("+");
			printf("%gx^2",a2);
		}
		else
			printf("%gx^2",a2);
	}
	
	if(a2==1)
	{
		if(a3!=0)
		printf("+");
		printf("x^2");
	}
	if(a2==-1)
		printf("-x^2");		
	if(a1!=1&&a1!=-1&&a1!=0)
	{	
		if(a1>0)
		{
			if(a3!=0||a2!=0)
				printf("+");			
			printf("%gx",a1);
		}
		else
			printf("%gx",a1);
	}
	
	if(a1==1)
	{
		printf("+x");
	}
	if(a1==-1)
		printf("-x");		
	if(a0<0)
		printf("%.lf",a0);
	if(a0>0)
		if(a1==0&&a2==0&&a3==0)
			printf("%g",a0);
		else
			printf("+%g",a0);
																																							
}
void write_polynomial4(double a0, double a1, double a2, double a3 , double a4)
{
	read_polynomial4(&a4, &a3, &a2, &a1, &a0);	
	if(a4!=1&&a4!=-1&&a4!=0)
		printf("%gx^4",a4);
	if(a4==1)					/*This function writes the polynomial in a pretty format.*/
		printf("x^4");
	if(a4==-1)
		printf("-x^4");				/*The coefficients were checked for positive, negative and zero. (For the all coefficients.)*/
	if(a4!=0&&a3!=0)
		printf("+");	
	if(a3!=1&&a3!=-1&&a3!=0)		
		printf("%gx^3",a3);
	if(a3==1)						/*The same operations were done for a fourth-order polynomial.*/
		printf("x^3");
	if(a3==-1)
		printf("-x^3");
	if(a2!=1&&a2!=-1&&a2!=0)
	{	
		if(a2>0)
		{	
			if(a3!=0&&a2!=0)
				printf("+");
			printf("%gx^2",a2);
		}
		else
			printf("%gx^2",a2);
	}
	
	if(a2==1)
	{
		if(a3!=0||a4!=0)
		printf("+");
		printf("x^2");
	}
	if(a2==-1)
		printf("-x^2");		
	if(a1!=1&&a1!=-1&&a1!=0)
	{	
		if(a1>0)
		{
			if(a3!=0||a2!=0||a4!=0)
				printf("+");			
			printf("%gx",a1);
		}
		else
			printf("%gx",a1);
	}
	
	if(a1==1)
	{
		printf("+x");
	}
	if(a1==-1)
		printf("-x");		
	if(a0<0)
		printf("%.lf",a0);
	if(a0>0)
		if(a1==0&&a2==0&&a3==0)
			printf("%g",a0);
		else
			printf("+%g",a0);

}
