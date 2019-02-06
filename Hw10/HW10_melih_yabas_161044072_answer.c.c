#include<stdio.h>
#include<stdlib.h>
#include <time.h>
typedef struct list{
	double num;
	struct list * next;	/*This is a structer to use the Linked List.*/

}linkedlist;

linkedlist *first = NULL, *last = NULL, *new, *temp, *del;

double readLine();
void recordArray();	/*Fuctions prototoypes were written to use.*/
void recordList();
double lineCounter();


int main(){
	int i,choice=5;
	
	printf("All prime numbers between 1 and 1.000.000 will write in the files.\nWould you like to countinue?\nYes:1 No:2\nChoice:");
	scanf("%d",&choice);
	if(choice==1)	/*If the user says yes, all functions will work.*/
	{
	  	recordArray();
 		recordList();			
	}

	while (temp != NULL)
	{			/*This loop was written to be free the linked list.*/
		del = temp;
		temp = temp->next;
		free(del);
		if(temp == NULL)
			break;
	}
	return 0;
}

double readLine(FILE *u){
	double a;		/*This function read a line and returns it.*/
	fscanf(u,"%lf,00", &a);
	return a;
}

void recordArray(){
	double size;
	FILE * x;
	FILE * prime;
	x = fopen("data.txt","r");	/*data.txt was opened.*/
	prime = fopen("output_even_dynamicarray.txt","a");
	int i,j,flag=1;
	double *array;	
	size = lineCounter(x);	
	array = (double*)calloc(size,sizeof(double));	/*A place was reserved from the ram for the array.*/
	for(i=0 ; i<size ; i++)
	{
		array[i] = readLine(x);
	}
	clock_t start1m, end1m;
	double time_spent1m;
	 start1m = clock();	/*clock() function was used to calculate calculation times.*/
	clock_t start750, end750;
	double time_spent750;
	 start750 = clock();	  
	clock_t start500, end500;
	double time_spent500;
	 start500 = clock();	

	printf("Please wait for calculation of prime numbers...\n");
	for(i=0 ; i<size ; i++)
	{
		flag=1;
		for(j=2 ; j<array[i]/2 ; ++j)
		{
			if((int)array[i]%j==0)
			{		/*This is a simple prime calculation.*/
				flag=0;
				break;
			}	
		}
		if(i==500000)
		{
			end500 = clock();/*To calculate the time between 1 and 500000*/
			time_spent500 = (double)(end500 - start500) / CLOCKS_PER_SEC;

		}
		if(i==750000)/*To calculate the time between 1 and 750000*/
		{
			end750 = clock();
			time_spent750 = (double)(end750 - start750) / CLOCKS_PER_SEC;

		}
		if(i==999999)/*To calculate the time between 1 and 1000000*/
		{
			end1m = clock();
			time_spent1m = (double)(end1m - start1m) / CLOCKS_PER_SEC;	
		}
	}	
	
	double time_spent;
	clock_t start, end;	
	 start = clock();	
	
	for(i=0 ; i<size ; i++)
	{
		flag=1;
		for(j=2 ; j<array[i]/2 ; ++j)/*This loops written to calculate the writing times.*/
		{
			if((int)array[i]%j==0)
			{
				flag=0;
				break;
			}	
		}
		if(flag==1&&array[i]!=1&&array[i]!=4)
		{	
			fprintf(prime,"%0.lf,00\n",array[i]);
			printf("%0.lf,00\n",array[i]);	
		}
	}		
	
		end = clock();
		
		time_spent = (double)(end - start) / CLOCKS_PER_SEC;	

	fprintf(prime,"Calculation time between 1 and 500.000:  %lf milliseconds\n",time_spent500*1000);	
	fprintf(prime,"Calculation time between 1 and 750.000:  %lf milliseconds\n",time_spent750*1000);	
	fprintf(prime,"Calculation time between 1 and 1.000.000:  %lf milliseconds\n",time_spent1m*1000);						
	fprintf(prime,"Written time between 1 and 1.000.000:  %lf milliseconds\n",time_spent*1000);	

	fclose(prime);
	fclose(x);/*The files were closed.*/
	
	free(array);
}

void recordList(){
	double size;
	FILE * x;	/*The necessary files were opened.*/
	FILE * prime;
	x = fopen("data.txt","r");
	prime = fopen("output_prime_LiknedList.txt","a");
	
	size = lineCounter(x);

	int i,j,flag=1;
	new = (linkedlist*)calloc(size,sizeof(linkedlist));		/*Linked list were occured.*/
	
	
	clock_t start1m, end1m;
	double time_spent1m;
	 start1m = clock();	/*clock() function was used to calculate calculation times.*/
	clock_t start750, end750;
	double time_spent750;
	 start750 = clock();	  
	clock_t start500, end500;
	double time_spent500;
	 start500 = clock();
	clock_t start, end;
	double time_spent;		
	 start = clock();	
		 	
	 	
	printf("Please Wait for Calculation of prime numbers...\n");
	temp = first;
	for(i=0 ; i<size ; i++)
	{
		new -> num = readLine(x);
		new -> next = NULL;

		if(first == NULL)
		{
			first = new;	/*All numbers between 1 and 1000000 were written in the linked list.*/
			last = first;
		}
		else
		{
			last -> next = new;
			last = last -> next;
		}	
		flag=1;
		for(j=2 ; j<(new -> num)/2 ; ++j)
		{
			if((int)(new -> num)%j==0)/*This is a simple prime calculation.*/
			{
				flag=0;
				break;
			}	
		}
		if(flag==1&&new -> num!=1&&new -> num!=4)
		{	
			fprintf(prime,"%0.lf,00\n",new -> num);
			printf("%0.lf,00\n",new -> num);
			end = clock();					
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;					

		}		
		
		if(i==500000)
		{
			end500 = clock();/*To calculate the time between 1 and 500000*/


			time_spent500 = (double)(end500 - start500) / CLOCKS_PER_SEC;

		}
		if(i==750000)
		{
			end750 = clock();/*To calculate the time between 1 and 750000*/
			time_spent750 = (double)(end750 - start750) / CLOCKS_PER_SEC;

		}
		if(i==999999)
		{

			end1m = clock();/*To calculate the time between 1 and 1000000*/

			time_spent1m = (double)(end1m - start1m) / CLOCKS_PER_SEC;

		}
	}

	fprintf(prime,"Calculation time between 1 and 500.000:  %lf milliseconds\n",time_spent500*1000);	
	fprintf(prime,"Calculation time between 1 and 750.000:  %lf milliseconds\n",time_spent750*1000);	
	fprintf(prime,"Calculation time between 1 and 1.000.000:  %lf second\n",time_spent1m*1000);						
	fprintf(prime,"Written time between 1 and 1.000.000:  %lf milliseconds\n",time_spent*1000);	
	printf("All prime numbers between 1 and 1.000.000 were written in the files.\nAdditionally, calculation times and writing times were written.");
	fclose(prime);/*The files were closed.*/
	fclose(x);
}	

double lineCounter(FILE *u){

	double k=0;
	char ch;/*This is a function that calculate the line number of a file*/
	u = fopen("data.txt" , "r");
	while(!feof(u))
	{
		ch=getc(u);
		if(ch=='\n') k++; 
	}
	
	return k;
}


