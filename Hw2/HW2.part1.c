#include <stdio.h>
#include <stdlib.h>
void LetterGrade(int num); /*A prototype to be used was written.*/ 

int main() {


	srand(40);
	int min = 0,max = 0,num = 0,total = 0,indexMin = 0,indexMax = 0,countA = 0,countB = 0,countC = 0,countD = 0,countF = 0,counter = 0 ;

	double avg = 0; /*Variables to be used are specified.*/
	int count;
	printf("Enter student count:");
	scanf("%d", &count);

	
	while(count<3||count>50)
	{
		printf("\n\nNot in Range!!!\n"); /*A loop was occured to get a student count between 3 and 50.*/
		printf("Enter student count:");
		scanf("%d", &count);		
	}
	

	int i,j;
	for(i=0 ; i<count ; i++)
	{
		counter++;
		num = rand()%101;
		if(num>=90&&num<=100)		
		countA++;							/*A loop was occured to find the score of most successfully, the most unsuccessfully student.*/				
		if(num>=80&&num<=89)
		countB++;
		if(num>=70&&num<=79)
		countC++;										/*	To find index these students.*/
		if(num>=60&&num<=69)
		countD++;
		if(num<=59)
		countF++;
		if(i==0)
		{
			min = num;
			
		}
		else if(num<min)
		{
			min = num;
			indexMin = counter;

		}													/*	To calculete the average of all students.	*/
		if(num>max)
		{
			max = num;
			indexMax = counter;
		}


		printf("%d ",num);
		total+=num;
		for(j=1;j<6;j++)
		{
			if(counter==j*10)
				printf("\n");
		}
	}
	
	
		avg = (double)total/count;
		int select;	
		if(count==-1)
			select=-1;
	
		for( ;select!=-1; )	
		{
			printf("\n------------------------------------------------------------------------------------------\n");
			printf("Student Score Calculator Menu for %d Student\n\n1)Most Successful Student\n2)Most Unsuccessful Student\n3)Letter Grade Statistics\n4)Calculate Average\n5)Show all Data\n\t\t\tMake Selection:",count);
							/*	a for loop was created for the menu and the results*/
			scanf("%d", &select);
	
			switch(select)
			{						/*Switch-Case Structures were used to show results.*/
				case 0:
					printf("False Selection!!!");
					break;
				case 1:
					printf("Most Successfully student:\nIndex:%d \nScore :%d\n",indexMax,max);
					LetterGrade(max);
					break;	
				case 2:
					printf("Most Unsuccessfully student:\nIndex:%d \nScore:%d\n",indexMin,min);
					LetterGrade(min);				
					break;
				case 3:
					printf("\n%d student got letter grade 'A'\n%d student got letter grade 'B'\n%d student got letter grade 'C'\n%d student got letter grade 'D'\n%d student got letter grade 'F'\n",countA,countB,countC,countD,countF);
					break;			
				case 4:
					printf("The average score of %d Student is %.2lf\n",count,avg);
					break;	
				case 5:
					printf("Most Successfully student:\nIndex:%d \nScore :%d\n",indexMax,max);
					LetterGrade(max);
					printf("Most Unsuccessfully student:\nIndex:%d \nScore:%d\n",indexMin,min);
					LetterGrade(min);
					printf("%d student got letter grade 'A'\n%d student got letter grade 'B'\n%d student got letter grade 'C'\n%d student got letter grade 'D'\n%d student got letter grade 'F'\n\n",countA,countB,countC,countD,countF);									
					printf("The average score of %d Student is %.2lf\n",count,avg);				
							
			}
			
		}
	
		return 0;
	}
	
	void LetterGrade(int num)
	{					/*This function was created for calculating letter grade.*/
			if(num>=90&&num<=100)
				printf("Letter Grade:A\n\n");
			if(num>=80&&num<=89)
				printf("Letter Grade:B\n\n");
			if(num>=70&&num<=79)
				printf("Letter Grade:C\n\n");
			if(num>=60&&num<=69)
				printf("Letter Grade:D\n\n");
			if(num<=59)
				printf("Letter Grade:F\n\n");
		
	}

