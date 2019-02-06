#include <stdio.h>
#include <stdlib.h>	/*Necessary libraries for functions were created.*/
#include <time.h>
#include <math.h>

void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();	/*Prototypes of the functions to be written were created.*/
void countOccurrence();
void triangleOfSequences();

int main()
{

	srand(time(NULL));	/*A random number function was written.*/
	menu();	/*The menu function has been called.*/

	return 0;
}

void menu()
{

	int choice;

	do
	{	
		printf("1. Horse Racing Game\n2. Occurrence Counter\n3. Triangle of Sequences\n0. Exit\nYour Choice: ");
		scanf("%d", &choice);	
		switch(choice)
		{
			case 1:
				horseRacingGame();
				break;	/*Menu was created with Switch Case and Do While.*/
			case 2:
				countOccurrence();	
				break;
			case 3:
				triangleOfSequences();	
				break;					
		}
		printf("\n");	
	}while(choice!=0);
	
}

int numberGeneratorBetweenRange(int min, int max)
{
	/*A function that generates a random number between the entered minimum and maximum numbers was written.*/
	return min+rand()%(max-min+1);
	
}

int getInt(int mini, int maxi)
{
	int number;
	do
	{	/*A function that take the number between values was written.*/
		printf("Horse Number: ");
		scanf("%d", &number);		
		
	}while(number<mini||number>maxi);
	
	return number;
	
}

void horseRacingGame() /*The horse racing game function was written.*/
{
	int num = numberGeneratorBetweenRange(3,5);
	int r1, r2, r3, r4, r5, i,j;
	printf("Number of Horse: %d\n",num);
	int myNum = getInt(1,num);
	printf("Racing starts...\n");
	
	r1 = numberGeneratorBetweenRange(10, 20);
	r2 = numberGeneratorBetweenRange(10, 20);	/*Each letter r represents a horse.*/
	r3 = numberGeneratorBetweenRange(10, 20);
	r4 = numberGeneratorBetweenRange(10, 20);
	r5 = numberGeneratorBetweenRange(10, 20);	
	
	printf("Horse 1: ");
	for(i=1 ; i<=r1 ; i++)
		printf("-");
	printf("\n");
	
	printf("Horse 2: ");
	for(j=1 ; j<=r2 ; j++)
		printf("-");
	printf("\n");
								/*Running times of horses were randomly generated and written with '-'.*/
	if(num >= 3)
	{
		printf("Horse 3: ");
		for(i=1 ; i<=r3 ; i++)
			printf("-");
		printf("\n");
	}
	if(num >= 4)
	{
		printf("Horse 4: ");
		for(i=1 ; i<=r4 ; i++)
			printf("-");
		printf("\n");					
	}
	if(num >=5)
	{
		printf("Horse 5: ");
		for(i=1 ; i<=r5 ; i++)
			printf("-");
		printf("\n");		
	}
	
	int min = 0;
		min=r1;
	if(r2<min)				/*The fastest horse was assigned to min.*/
		min=r2;
	if(r3<min)
		min=r3;
	if(num>=4)
	{	
		if(r4<min)
			min=r4;	
	}
	if(num>=5)
	{
		if(r5<min)
			min=r5;
	}
	if(myNum==1)
		myNum = r1;
	if(myNum==2)
		myNum = r2;				/*The variable that is equal to the value that the user entered is assigned.*/
	if(myNum==3)
		myNum = r3;	
	if(myNum==4)
		myNum = r4;	
	if(myNum==5)
		myNum = r5;	
			
	if(min==myNum)	
	{
		if(min==myNum&&min==r1)
			printf("You win! Winner is Horse 1.\n");
		else if(min==myNum&&min==r2)
			printf("You win! Winner is Horse 2.\n");	/*Winning status checked.*/
		else if(min==myNum&&min==r3)
			printf("You win! Winner is Horse 3.\n");
		else if(min==myNum&&min==r4)
			printf("You win! Winner is Horse 4.\n");
		else if(min==myNum&&min==r5)
			printf("You win! Winner is Horse 5.\n");	
	}
	else
	{
		if(min==r1)
			printf("You lose! Winner is Horse 1.\n");				
		else if(min==r2&&min!=r1)
			printf("You lose! Winner is Horse 2.\n");	
		else if(min==r3&&min!=r2)
			printf("You lose! Winner is Horse 3.\n");	
		if(num>=4)												/*losing status checked.*/
		{	
			if(min==r4&&min!=r3)
				printf("You lose! Winner is Horse 4.\n");	
		}
		if(num>=5)
		{
			if(min==r5&&min!=r4)
				printf("You lose! Winner is Horse 5.\n");	
		}
	}
}

void countOccurrence()	/*A program computes number of occurrences of searchNumber in bigNumber was written.*/
{
	int numberB, numberS;
	printf("Big Number: ");
	scanf("%d", &numberB);
	printf("Search Number: ");
	scanf("%d", &numberS);
	int digitB = 0, digitS = 0, i;
	int occurence = 0;		
	int tempB = numberB;
	int tempS = numberS;
	while(tempB!=0)
	{
		tempB = tempB/10;			/*The digit how many places is found.*/
		digitB++;
	}	
	while(tempS!=0)
	{
		tempS = tempS/10;			/*The digit how many places is found.*/
		digitS++;
	}
	if(numberS == 0)
		digitS = 1;
	for(i=0 ; i<digitB ; i++)
	{
		if((numberB/((int)pow(10,i)))%(int)pow(10,digitS)==numberS)
			occurence++;			
	}
	printf("Occurence: %d\n",occurence);
}

void triangleOfSequences()
{
	int num, i, j;
	num = numberGeneratorBetweenRange(2, 10);
	
	for(i=1 ; i<=num ; i++)		/*A program with 2 for loop and random number function written. It generates a triangle with numbers.*/
	{
		
		for(j=1 ; j<=i ; j++)
		{
			printf("%d ",j*i);
		}
		printf("\n");
	}
	printf("\n");
	
}
