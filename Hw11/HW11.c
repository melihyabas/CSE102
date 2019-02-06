#include<stdio.h>
#include<stdlib.h>	/*The necessary libraries.*/
#include<string.h>

typedef struct customers{
	char surname[20];
	char name[20];	/*This struct was written to create customers list*/
	int age;
	char gender[20];

	struct customers *next;

}customers;

typedef struct rooms{
	int number;
	int capacity; /*This struct was written to create rooms list*/
	int floor;

	struct rooms *next;

	customers *customers;

}rooms;

void add_room_to_end(int number, int capacity, int floor, rooms *r);
void add_room_after_room_number(int givenNum, int number, int capacity, int floor, rooms *r);
void add_customer_to_end(char nam[20], char surnam[20], int age, char gend[20],customers *cus, rooms *r, int room);
void link_customers_to_room(int room,  rooms *r, customers *cus);
void remove_room (int number, rooms *r);
void show_vacancy(rooms *r);/*These are fuctions prototypes.*/
void get_by_floor(int floor, rooms *r);
void print_list (rooms *r);

int main()
{
	int number, capacity, floor, age, room, i;
	char nam[20], surnam[20], gend[20];

	rooms *r;
	r = (rooms*)malloc(sizeof(rooms));
	r->next = NULL;/*For the rooms, a necessary place was occured.*/

	customers *cus;/*For the customers, a necessary place was occured.*/
	cus = (customers*)malloc(sizeof(customers));
	cus->next = NULL;

		
	FILE *rooms;

	rooms = fopen("rooms.txt","r");
	while(!feof(rooms))
	{	

		fscanf(rooms,"%d,%d,%d", &number, &capacity, &floor);
		/*Information was taken in rooms.txt file.*/
		add_room_to_end(number, capacity, floor,r);

	}

	fclose(rooms);

	FILE *customers;

	customers = fopen("customers.txt","r");
	while(!feof(customers))
	{
		char line[40];
		char *c;
		c = fgets(line,40,customers);

		for(i=0 ; i<40 ; i++)
		{
			if(line[i]==',')
				line[i] = ' ';
		}
		/*Information was taken in customers.txt file.*/

		sscanf(line,"%d%s%s%d%s", &room, nam, surnam, &age, gend);	

		add_customer_to_end(nam, surnam, age, gend, cus, r, room);
	}
	

	/*THESE ARE THE TEST FUNCTIONS TO CONTROL PROGRAM.*/
	/*show_vacancy(r);*/
	/*remove_room (204, r);*/
	/*get_by_floor(1, r);*/
	/*add_room_after_room_number(103, 99, 10, 3, r);*/



	print_list (r);


	fclose(customers);

	return 0;
}

void add_room_to_end(int number, int capacity, int floor, rooms *r)
{
		while(r->next!=NULL)
		{
			r = r->next;	/*This function add a new room to the end of room linked list.*/
		}	
		r->next = (rooms*)malloc(sizeof(rooms));	

		r->next->number = number;
		r->next->capacity = capacity;
		r->next->floor = floor;	
		r->next->next = NULL;
}

void add_customer_to_end(char nam[20], char surnam[20], int age, char gend[20], customers *cus, rooms *r, int room)
{

		int i;
		while(cus->next!=NULL)
		{
			cus = cus->next;	/*This function add a new customer to the end of customer linked list.*/
		}		
		cus->next = (customers*)malloc(sizeof(customers));	
		
		strcpy(cus->next->name,nam);
		strcpy(cus->next->surname,surnam);
		strcpy(cus->next->gender,gend);
		cus->next->age = age;
		cus->next->next = NULL;

		link_customers_to_room(room, r, cus);	/*To link customers to his/her room.*/

}

void link_customers_to_room(int room,  rooms *r, customers *cus)
{
	rooms *head = (rooms*)malloc(sizeof(rooms));
	head = r;
	while(r!=NULL)
	{		/*Until the room equals the room in the linked list. It returns.*/
		if(r->number == room)
			break;

		r = r->next;
	}
	if(r==NULL)
	{
			return;
	}					

	if(r->customers==NULL)
	{	
		r->customers = (customers*)malloc(sizeof(customers));
		r->customers = cus->next;

		r->customers->next = NULL;
	}	
			/*A customer links the room.*/
	else
	{
		while(r->customers->next!=NULL)
			r->customers = r->customers->next;

		r->next->customers = (customers*)malloc(sizeof(customers));
	
		r->next->customers = cus->next;
		r->next->customers->next = NULL;

	}
}

void print_list (rooms *r)
{
	rooms *h = (rooms*)malloc(sizeof(rooms));
	h = r;
	
	while(h->next!=NULL)
	{
		printf("Room %d (Floor %d - capacity %dx):\n",h->next->number,h->next->floor,h->next->capacity);
		if(h->next->customers==NULL)	/*The rooms and customers are printed in the screen.*/
			printf("-> Empty");		
		if(h->next->customers!=NULL)
		{	
			printf("->%s %s (%d - %s)",h->next->customers->name,h->next->customers->surname,h->next->customers->age,h->next->customers->gender);
			h->next->customers = h->next->customers->next;
			printf("\n");
		}

		printf("\n\n");
		h = h->next;

	}
}

void add_room_after_room_number(int givenNum, int number, int capacity, int floor, rooms *r)
{
	while(r->next!=NULL)
	{
		r = r->next;
		if(r->number == givenNum)
		{		/*A room is able to add after anoter room.*/
			rooms *temp = (rooms*)malloc(sizeof(rooms));
			temp = (rooms*)malloc(sizeof(rooms));
			temp->next = r->next;
			r->next = temp;
			temp->number = number;
			temp->capacity = capacity;
			temp->floor = floor;
			return;
		}
	}
	if(r->next==NULL)
	{
		r->next = (rooms*)malloc(sizeof(rooms));	

		r->next->number = number;
		r->next->capacity = capacity;
		r->next->floor = floor;	
		r->next->next = NULL;	
	}
}

void remove_room (int number, rooms *r)
{
	while(r->next->number != number)
	{
		r = r->next;
	}	/*This function removes a room.*/

	printf("\n*Room %d was deleted.*\n",r->next->number);

	rooms *temp = (rooms*)malloc(sizeof(rooms));
	temp = (rooms*)malloc(sizeof(rooms));	

	temp = r->next;
	r->next = r->next->next;
	free(temp);
}

void get_by_floor(int floor, rooms *r)
{
	printf("%d. floor's rooms:\n",floor);
	while(r->next != NULL)
	{	/*This function shows us the rooms in given floor.*/
		if(r->next->floor == floor)
		{
			printf("Room %d\n",r->next->number);
		}
		r = r->next;
	}

}

void show_vacancy(rooms *r)
{
	printf("These rooms are empty:\n");

	while(r->next!=NULL)
	{
		if(r->next->customers==NULL)
			printf("Room %d\n",r->next->number);		

		r=r->next;

	}	/*This function shows us empty rooms.*/
	
	while(r->next!=NULL)
	{
		printf("Room %d (Floor %d - Capacity %dx):\n",r->next->number,r->next->floor,r->next->capacity);
		if(r->next->customers==NULL)
			printf("-> Empty");		
		if(r->next->customers!=NULL)
		{	
			printf("->%s %s (%d - %s)",r->next->customers->name,r->next->customers->surname,r->next->customers->age,r->next->customers->gender);
			r->next->customers = r->next->customers->next;
			printf("\n");
		}

		printf("\n\n");
		r=r->next;
	}	
}