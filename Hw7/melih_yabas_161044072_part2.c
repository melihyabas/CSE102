#include <stdio.h>
int date_control(int day, int month, int year);

int main () {
	int day, month, year,i,j,k;
	int day2, month2, year2; 	/*Required variables are defined.*/
	char x;
	char date[100];
	char date2[100];
	
	FILE *inputDate;		
	
	inputDate=fopen("input_date.txt","w");
	
	printf("Start Date(dd/MM/yyyy):");	/*The file was opened and the dates were retrieved.*/
	for(i=0 ; i<10 ; i++)
	{
		scanf("%c",&date[i]);
	}
	
	sscanf(date, "%d%c%d%c%d ", &day,&x,&month,&x,&year);
	printf("Finish Date(dd/MM/yyyy):");
	for(i=0 ; i<11 ; i++)
	{
		scanf("%c",&date2[i]);
	}
	
	sscanf(date2, "%d%c%d%c%d ", &day2,&x,&month2,&x,&year2);

		while(day!=day2||month!=month2||year!=year2)	
		{

			if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)	
			{
				if(day==31)					/*It was determined according to the length of the months.*/
				{
					day=0;
					month+=1;
				}
			}
			else if(month==2)
			{
				if(year%4==0)
				{
					if(day==29)
					{
						day=0;
						month+=1;
					}	
				}
				else
				{
					if(day==28)
					{
						day=0;
						month+=1;
					}
				}
			}
			else
			{
				if(day==30)
				{
					day=0;
					month+=1;
				}
			}	
			
			if(month==13)
			{
				month=1;
				year+=1;	
			}
			
			day++;
			if(day!=day2||month!=month2||year!=year2)
			{
				fprintf(inputDate,"%02d/",day); /*The dates were written to the file.*/
				fprintf(inputDate,"%02d/",month);
				fprintf(inputDate,"%04d",year);
				fprintf(inputDate,"\n");			
			}
		}		
	printf("\ninput_date.txt include all days between the start and the end date.\n");
	printf("new_date.txt inlude all these days in new format.");
	fclose(inputDate);	

	/*!!!The doomsday algorithm was used.!!!*/

	int dc,mc,yc,dyc;
	/*dc:date code  mc:month code  yc:year code  dyc:day code*/			
	fopen("input_date.txt","r");
	FILE *newDate;					/*Dates were received from the file for the new format.*/
	newDate = fopen("new_date.txt","w"); 
	char arr[10];
	char *a;
	do	
	{
		a = fgets(arr,100,inputDate);
		if(a!=NULL)
		{
			sscanf(arr,"%d%c%d%c%d",&day,&x,&month,&x,&year);
			
			dc=day;
			yc=year%100;
			
			switch(month)
			{
				case 1:
				case 10:
					mc=1;
					break;
				case 2:		/*Month code was specified.*/
				case 3:
				case 11:
					mc=4;
					break;
				case 4:
				case 7:
					mc=7;
					break;
				case 5:
					mc=2;
					break;
				
				case 6:
					mc=5;
					break;
				case 8:
					mc=3;
					break;
				case 9:
				case 12:	
					mc=6;
					break;						
			}
			
			if(year<2000)
				dyc = (dc%7)+mc+(yc%7)+(yc/4)%7;
			else
				dyc = (dc%7)+mc+(yc%7)+(yc/4)%7-1;
		
			dyc%=7;
				
			switch(dyc)
			{
				case 1:
					fprintf(newDate,"Sunday, ");
					break;
				case 2:
					fprintf(newDate,"Monday, ");
					break;				/*Weekday was printed to newDate.txt*/
				case 3:
					fprintf(newDate,"Tuesday, ");
					break;
				case 4:
					fprintf(newDate,"Wednesday, ");
					break;
				case 5:
					fprintf(newDate,"Thursday, ");
					break;
				case 6:
					fprintf(newDate,"Friday, ");
					break;
				case 0:	
					fprintf(newDate,"Saturday, ");
					break;
			}
			
			switch(month)
			{
				case 1:
					fprintf(newDate,"January ");
					break;
				case 2:
					fprintf(newDate,"February ");
					break;			
				case 3:
					fprintf(newDate,"March ");
					break;			
				case 4:
					fprintf(newDate,"April ");
					break;			
				case 5:
					fprintf(newDate,"May ");	/*The month was printed to the newdate.txt*/
					break;			
				case 6:
					fprintf(newDate,"June ");
					break;			
				case 7:
					fprintf(newDate,"July ");
					break;			
				case 8:
					fprintf(newDate,"August ");
					break;			
				case 9:
					fprintf(newDate,"September ");
					break;			
				case 10:
					fprintf(newDate,"October ");
					break;			
				case 11:
					fprintf(newDate,"November ");
					break;			
				case 12:
					fprintf(newDate,"December ");
					break;			
			}
			fprintf(newDate,"%d, ",day);
			fprintf(newDate,"%d\n",year);				
			
		}
	}while(a!=NULL);
		
		fclose(inputDate); /*All files were closed.*/
		
   return 0;
}
