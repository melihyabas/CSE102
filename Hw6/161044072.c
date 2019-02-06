#include <stdio.h>
#include <stdlib.h>

void menu();	
void encrypt_open_msg();	/*These prototypes of functions.*/ 
void decrypt_secret_msg(); 
int find_size_of_line(char line[]); 
void reverse_line(char line[], int line_lenght); 

int main() 
{	
	menu();	/*It runs menu function.*/


	return 0;
}

void menu()
{

	int choice;

	do
	{	
		printf("\n1. Encrypt\n2. Decrypt\n0 .Exit\nChoice:");
		scanf(" %d", &choice);	/*These show the menu and take a choice from the user.*/
		switch(choice)	
		{
			case 1:
				encrypt_open_msg();
				break;	/*Menu was created with Switch Case and Do While.*/
			case 2:
				decrypt_secret_msg();	
				break;
			
		}
		printf("\n");	
	}while(choice!=0);

}

void encrypt_open_msg()
{
	
 	int i,j,k;
 	int key;	/*Variables created that we will use.*/

	FILE *encr;		
	FILE *secr=fopen("secret_msg.txt","w");
	char arr[1024];	
	i=0;

	if((encr=fopen("open_msg.txt","r"))!=NULL)
	{
		while(!feof(encr))	/*It reads characters from open_msg.txt.*/
		{
			fscanf(encr,"%c",&arr[i]);
			
			i++;
		}
	}
	arr[i-1]='\0';
	printf("%s",arr);
	
	
	fclose(encr);
	
 	char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 	
 	/*For the encryption, a key value was taken from the user.*/
 	printf("\nkey: ");
	scanf("%d",&key); 
	
	int size = find_size_of_line(arr);
		reverse_line(arr,size);	/*It used to reverse the characters of the array.*/
	for(i=0;i<=size;i++)
	{
		for(j=0;j<=26;j++)
		{		
			if(arr[i]==alp[j])
				{		/*These loops encrypt the string.*/
					j-=key;
					j=(j+26)%26;
					arr[i]=alp[j]; 
					break;	
				}
	    }
	}
	fprintf(secr,"%s",arr);
	fclose(secr);
 	printf("%s",arr);	
}
void decrypt_secret_msg()
{
 	int i,j,k;
 	int key;	/*Variables created that we will use.*/

	FILE *secr;		
	FILE *encr=fopen("open_msg.txt","w");
	char arr[1024];	
	i=0;

	if((secr=fopen("secret_msg.txt","r"))!=NULL)
	{
		while(!feof(secr))	/*It reads characters from secret_msg.txt.*/
		{
			fscanf(secr,"%c",&arr[i]);
			
			i++;
		}
	}
	arr[i-1]='\0';
	printf("%s",arr);
	
	
	fclose(secr);
	
 	char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 	
 	/*For the encryption, a key value was taken from the user.*/
 	printf("\nkey: ");
	scanf("%d",&key); 
	
	int size = find_size_of_line(arr);
		reverse_line(arr,size);	/*It used to reverse the characters of the array.*/
	for(i=0;i<=size;i++)
	{
		for(j=0;j<=26;j++)
		{		
			if(arr[i]==alp[j])
				{		/*These loops encrypt the string.*/
					j+=key;
					j=(j+26)%26;
					arr[i]=alp[j]; 
					break;	
				}
	    }
	}
	fprintf(encr,"%s",arr);	
	fclose(encr);
 	printf("%s",arr);	
}
int find_size_of_line(char line[])
{
	int size = 0;		/*This function calcutes the size of array.*/
	while(line[size]!='\0')	
		size++;
	
	return size-1;
}
void reverse_line(char line[], int line_lenght)
{		
	int i,j,k,a=0;	
	char temp = '0';	
	int first, last=0;

	while(line[last]!='\n')
		last++;
	
	first=0;			
	while(last<=line_lenght+1)
	{	
		/*This while loop reverse the array for each sentence.*/
		j=last-1;
		for(i=first;i<=(last+first)/2-1;i++)
		{
			temp=line[i];
			line[i]=line[j];
			line[j]=temp;
			j--;
		}

		first = last+1;
		last=first;
		while(line[last]!='\n'&&last<=line_lenght)
		{	
			last++;	
		}

	}

	for(i=0 ; i<=line_lenght ; i++)
	{
		if(line[i]==' ')
			line[i]='_';
		else if(line[i]=='.')	/*This is another loop was written for the encription and decyription.*/
			line[i]='*';
		else if(line[i]=='*')
			line[i]='.';
		else if(line[i]=='_')
			line[i]=' ';							
	}	

}
