#include <stdio.h>

int main() 
{

	int counter = 0;
	int number, first, second, third, fourth, fifth; /*Variables to be used are specified.*/
	
	printf("Enter the Number:");
	scanf("%d", &number);
	if(number>23&&number<98760)
	{
		first = number%10;
		second = (number/10)%10;
		third = (number/100)%10;	/*The digit places are found*/
		fourth = (number/1000)%10;
		fifth = (number/10000)%10;
		
		while(number!=0)
		{
			number = number/10;			/*The digit how many places is found.*/
			counter++;
		}
		
		printf("\n");
		switch(counter)
		{
			case 5:
				printf("\nThe fifth digit is %d\n",fifth);	
			case 4:
				printf("The fourth digit is %d\n",fourth);	/*The digit places were printed.*/
			case 3:
				printf("The third digit is %d\n",third);				
			case 2:
				printf("The second digit is %d\n",second);				
			case 1:
				printf("The first digit is %d\n",first);									
		}
	}
	else
		printf("You must enter a number between 23 and 98760");	/*'Else' was created for the other numbers.*/

	return 0;
}
