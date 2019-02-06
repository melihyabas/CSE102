/*Bu kod Dev C++'ta sorunsuz çalýþmaktadýr.*/


#include<stdio.h>	/*It is necessary for the printf, scanf etc. many important functions.*/
#include<stdlib.h>	/*It is necesssary for the random number function..*/
#include<time.h>

typedef struct{
	int **map;
	int width;	/*This structure was defined for the features of forest.*/
	int height;
	int flower_x;
	int flower_y;
	
}Forest;

typedef struct{
	int coord_x;
	int coord_y;	/*This structure was defined for the features of botanist.*/
	int water_bottle_size;
}Botanist;

void init_game(Forest *forest, Botanist *botanist);
void print_map (Forest *forest);				/*The function prototypes were defined.*/
void search (Forest *forest, Botanist *botanist);

int main()
{
	int i;
	srand(time(NULL));
	Forest forest;
	Botanist botanist;
	init_game(&forest, &botanist);	/*In the main function, the other functions were called.*/
	print_map (&forest);
	printf("\nSearching...\n\n");
	search (&forest ,&botanist); 	
	printf("\n");
 	
	for(i=0 ; i<forest.height ; i++)
	{
		free(forest.map[i]);
	}									/*Memory were free.*/

	free(forest.map);
	
	return 0;
}

void init_game(Forest *forest, Botanist *botanist)
{

	int i,j,k;
    FILE *game;				
 	char *array;						/*This is a one dimesional array to get the characters. */
    game = fopen("init.txt", "r");
    
	fscanf(game,"%d", &botanist->water_bottle_size);
	fscanf(game,"%d,%d", &forest->height,&forest->width);	/*First, integers were taken.*/
	
	array = (char*)malloc(2*forest->height*forest->width*sizeof(char));
	
	forest->map = (int **)calloc( forest->height , sizeof(int*) );	/*For the array and our map, memory allocation was did.*/
	
	for(i=0 ; i<forest->height ; i++) 
	{
		forest->map[i] = (int*)calloc( forest->width , sizeof(int) );
	}
																	
	for(i=0 ; i<(2)*(forest->height)*(forest->width) ; i++)
	{	
		fscanf(game,"%c", &array[i]); 					/*All characters were taken in array.*/
	}
	i=0;
	for(k=0 ; k<forest->height ; k++)
	{
		for(j=0 ; j<forest->width ; j++)			/*The necessary characters were taken from array to the map.*/
		{
			while(array[i]!=' '&& array[i]!='B' && array[i]!='F' && array[i]!='#')
			{
				i++;
			}
			if(array[i]==' '||array[i]=='B'||array[i]=='F'||array[i]=='#')
			{	
				
				forest->map[k][j]=array[i];	
			}
			i++;	
			
		}
	}

	free(array);	
    fclose(game);	
	
}

void print_map (Forest *forest)
{
	
	int i,j;				/*This function just print the map.*/
	
	
	for(i=0 ; i<forest->height ; i++)
	{
		for(j=0 ; j<forest->width ;j++)	/*The nested loops did it.*/
		{
			printf("%c ",forest->map[i][j]);
		}
		printf("\n");
	}	
}

void search (Forest *forest, Botanist *botanist)
{	

	if(botanist->water_bottle_size==0)
	{
		print_map (forest);	/*When botanist's water was runned out, she stays in the coordinates.*/
		printf("\nHelp! I am on(%d,%d)",botanist->coord_x,botanist->coord_y);
		return;
	}
	
	char a='!',b='!',c='!',d='!',n='!';


	int w;
	int flag = 1;
	n = forest->map[botanist->coord_x][botanist->coord_y];
	if(botanist->coord_x>0)
		a = forest->map[botanist->coord_x-1][botanist->coord_y];	
	if(botanist->coord_x<9)
		b = forest->map[botanist->coord_x+1][botanist->coord_y];	/*These avoid x>9, y>9 or x<0, y<0*/
	if(botanist->coord_y<9)
		c = forest->map[botanist->coord_x][botanist->coord_y+1];
	if(botanist->coord_y>0)	
		d = forest->map[botanist->coord_x][botanist->coord_y-1];

	while(flag==1)
	{
		w = 1+rand()%4;
		
		if(w==1&&(a==' '||a=='F'))
		{	
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x-1][botanist->coord_y]='B';	/*'1' represents the up.*/
			botanist->coord_x = botanist->coord_x-1;
			
			if(a=='F')
			{
				print_map (forest);
				printf("I have found it on(%d,%d)!",botanist->coord_x,botanist->coord_y);
				return;
			}	
			
			flag=2;	
		}
		if(w==2&&(b==' '||b=='F'))
		{
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x+1][botanist->coord_y]='B';	/*'2' represents the bottom.*/
			botanist->coord_x = botanist->coord_x+1;	
			
			if(b=='F')
			{
				print_map (forest);
				printf("I have found it on(%d,%d)!",botanist->coord_x,botanist->coord_y);
				return;
			}		
			
			flag=2;

		}
		if(w==3&&(c==' '||c=='F'))
		{
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x][botanist->coord_y+1]='B';
			botanist->coord_y = botanist->coord_y+1;	/*'3' represents the right.*/
				
			if(c=='F')
			{
				print_map (forest);
				printf("I have found it on(%d,%d)!",botanist->coord_x,botanist->coord_y);
				return;
			}	
			
			flag=2;

		}
		if(w==4&&(d==' '||d=='F'))
		{
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x][botanist->coord_y-1]='B';	/*'4' represents the left.*/
			botanist->coord_y = botanist->coord_y-1;
			
			if(d=='F')
			{
				print_map (forest);
				printf("I have found it on(%d,%d)!",botanist->coord_x,botanist->coord_y);
				return;
			}	

			flag=2;

		}
	}
	
	botanist->water_bottle_size--;	/*This is botanist's size of water.*/
	if(botanist->water_bottle_size==0)
	{
		print_map (forest);	/*When botanist's water was runned out, she stays in the coordinates.*/
		printf("\nHelp! I am on(%d,%d)",botanist->coord_x,botanist->coord_y);
		return;
	}
	else if(botanist->water_bottle_size!=0)
		search(forest,botanist);	/*If she has a little water and she still does not find the flower, she repeats these movements.*/

}
