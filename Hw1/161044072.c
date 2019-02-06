#include <stdio.h>
#include <math.h>	/*Gerekli haz�r fonksiyonlar� kullanmak i�in k�t�phaneler yaz�ld�.*/
#define PI 3.14		/*Baz� i�lemlerde kullan�lacak pi say�s� tan�mland�.*/
double circle_area(double radius); 
double calc_hypotenuse(int side1, int side2); 
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);	/*Kullan�lacak fonksiyonlar�n prototipleri olu�turuldu.*/
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square);

int main()
{	
	int side1, side2;
	printf("Enter the sides of rectangle\nside1:");
	scanf("%d",&side1);
	printf("side2:");	/*Kullan�c�dan dikd�rtgenin kenar uzunluklar� al�nd�*/
	scanf("%d",&side2);
	
	display_results(calc_area_of_largest_circle(side1, side2), calc_area_of_largest_square(side1, side2), calc_area_of_smallest_circle(side1, side2), calc_area_of_smallest_square(side1, side2));	/*Ana fonksiyonda t�m i�lemlerin sonuca ba�land��� fonksiyon �a�r�ld�.*/
	
	return 0; 
}


double circle_area(double radius)
{
	double area = (PI*(pow(radius,2)));	/*Dairenin genel alan form�l�n� i�ere fonksiyon, pow fonksiyonu kullan�larak yaz�ld�.*/
	
	return area;
}


double calc_hypotenuse(int side1, int side2)
{
	double hypotenuse = sqrt((pow(side1,2))+(pow(side2,2))); /*Pow fonksiyonu ile hipoten�s� hesaplayan fonksiyon yaz�ld�.*/
	
	return hypotenuse;
	
}  

double calc_radius_of_smallest_circle(int side1, int side2)
{
	double radius = (calc_hypotenuse(side1, side2))/2;	/*Bir dikd�rtgeni �evreleyen en k���k �emberin yar��ap� �nceden yaz�lan hipoten�s fonksiyonu ile hesapland�.*/
	
	return radius;
}

double calc_radius_of_largest_circle(int side1, int side2)
{
	double radius;	
	
	if(side1>=side2)
	{
		radius = (double)side2/2;
	}
	else		/*Bir dikd�rtgene s��an en b�y�k �emberin yar��ap� k�sa kenar�n yar�s� al�narak hesapland�.*/
	{
		radius = (double)side1/2;
	}
	
	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2)
{
	double area = circle_area((calc_radius_of_smallest_circle(side1, side2)));
	
	return area;	/*Bir dikd�rtgeni �evreleyen en k���k dairenin alan� �nceden yaz�lan yar��ap ve alan fonksiyonlar� kullan�larak hesapland�.*/
}

double calc_area_of_largest_circle(int side1, int side2)
{
	double area = circle_area((calc_radius_of_largest_circle(side1, side2)));
	
	return area; /*Bir dikd�rtgene s��an en b�y�k dairenin alan� �nceden yaz�lan yar��ap ve alan fonksiyonlar� kullan�larak hesapland�.*/
}

double calc_area_of_smallest_square(int side1, int side2)
{
	double area;
	
	if(side1>=side2)
	{		/*Bir dikd�rtgeni �evreleyen en k���k karenin alan�, uzun kenar alan fonksiyonunda kullan�larak hesapland�. */
		area = calc_area_of_square (side1);
	}
	else
	{
		area = calc_area_of_square (side2);
	}
	
	return area;
}

double calc_area_of_largest_square(int side1, int side2)
{
	double area;
	
	if(side1>=side2)
	{		/*Bir dikd�rtgene s��an en b�y�k karenin alan�, k�sa kenar alan fonksiyonunda �a��r�larak hesapland�.*/
		area = calc_area_of_square (side2);
	}
	else
	{
		area = calc_area_of_square (side1);
	}
	
	return area;
}

double calc_area_of_square (int side)
{
	double area = pow(side,2);
					/*Karenin alan�n� hesaplayan fonksiyon pow fonksiyonu yard�m�yla yaz�ld��*/
	return area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square)
{
	
	printf("The area of the largest circle that fits inside a rectangle: %.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside the rectangle: %.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:  %.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle: %.2lf\n",smallest_square);
	/*Fonksiyonlarda hesaplanan de�erler printf fonksiyonu ile ekrana bas�ld�*/
	
}

