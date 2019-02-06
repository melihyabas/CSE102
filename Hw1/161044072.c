#include <stdio.h>
#include <math.h>	/*Gerekli hazýr fonksiyonlarý kullanmak için kütüphaneler yazýldý.*/
#define PI 3.14		/*Bazý iþlemlerde kullanýlacak pi sayýsý tanýmlandý.*/
double circle_area(double radius); 
double calc_hypotenuse(int side1, int side2); 
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);	/*Kullanýlacak fonksiyonlarýn prototipleri oluþturuldu.*/
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
	printf("side2:");	/*Kullanýcýdan dikdörtgenin kenar uzunluklarý alýndý*/
	scanf("%d",&side2);
	
	display_results(calc_area_of_largest_circle(side1, side2), calc_area_of_largest_square(side1, side2), calc_area_of_smallest_circle(side1, side2), calc_area_of_smallest_square(side1, side2));	/*Ana fonksiyonda tüm iþlemlerin sonuca baðlandýðý fonksiyon çaðrýldý.*/
	
	return 0; 
}


double circle_area(double radius)
{
	double area = (PI*(pow(radius,2)));	/*Dairenin genel alan formülünü içere fonksiyon, pow fonksiyonu kullanýlarak yazýldý.*/
	
	return area;
}


double calc_hypotenuse(int side1, int side2)
{
	double hypotenuse = sqrt((pow(side1,2))+(pow(side2,2))); /*Pow fonksiyonu ile hipotenüsü hesaplayan fonksiyon yazýldý.*/
	
	return hypotenuse;
	
}  

double calc_radius_of_smallest_circle(int side1, int side2)
{
	double radius = (calc_hypotenuse(side1, side2))/2;	/*Bir dikdörtgeni çevreleyen en küçük çemberin yarýçapý önceden yazýlan hipotenüs fonksiyonu ile hesaplandý.*/
	
	return radius;
}

double calc_radius_of_largest_circle(int side1, int side2)
{
	double radius;	
	
	if(side1>=side2)
	{
		radius = (double)side2/2;
	}
	else		/*Bir dikdörtgene sýðan en büyük çemberin yarýçapý kýsa kenarýn yarýsý alýnarak hesaplandý.*/
	{
		radius = (double)side1/2;
	}
	
	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2)
{
	double area = circle_area((calc_radius_of_smallest_circle(side1, side2)));
	
	return area;	/*Bir dikdörtgeni çevreleyen en küçük dairenin alaný önceden yazýlan yarýçap ve alan fonksiyonlarý kullanýlarak hesaplandý.*/
}

double calc_area_of_largest_circle(int side1, int side2)
{
	double area = circle_area((calc_radius_of_largest_circle(side1, side2)));
	
	return area; /*Bir dikdörtgene sýðan en büyük dairenin alaný önceden yazýlan yarýçap ve alan fonksiyonlarý kullanýlarak hesaplandý.*/
}

double calc_area_of_smallest_square(int side1, int side2)
{
	double area;
	
	if(side1>=side2)
	{		/*Bir dikdörtgeni çevreleyen en küçük karenin alaný, uzun kenar alan fonksiyonunda kullanýlarak hesaplandý. */
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
	{		/*Bir dikdörtgene sýðan en büyük karenin alaný, kýsa kenar alan fonksiyonunda çaðýrýlarak hesaplandý.*/
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
					/*Karenin alanýný hesaplayan fonksiyon pow fonksiyonu yardýmýyla yazýldýç*/
	return area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square)
{
	
	printf("The area of the largest circle that fits inside a rectangle: %.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside the rectangle: %.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:  %.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle: %.2lf\n",smallest_square);
	/*Fonksiyonlarda hesaplanan deðerler printf fonksiyonu ile ekrana basýldý*/
	
}

