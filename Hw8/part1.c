#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	char text[10];
	int data; 
	char type;	/*This a structure for the game arguments.*/
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;	
		
}block;

void printBoard(block board[][10]);
void startBoard(block board[][10]);	/*Prototoypes of the functions.*/
int singlePlayer(block board[][10], int x, int y, int counter);
void multiplayer(block board[][10]);

int main()
{
	int counter = 0, choice;
	srand(time(NULL));	
	block board[10][10];	/*These functions are written bottom.*/

	printf("Menu:\n1-Single Player\n2-Multiplayer\nChoice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			startBoard(board);
			printBoard(board);
			counter = singlePlayer(board, 9, 9, counter);	
			printf("\nThe Block Board:1(Start)");
			printf("\n---------------------------------------------------");
			printf("\nMove Count:%d",counter);
			break;		
		case 2:
			startBoard(board);
			printBoard(board);	
			multiplayer(board);							
			
	}

	return 0;
}

void startBoard(block board[][10])	/*This is a function that initialize the game board.*/
{
	int i,j,x=101;
	for(i=0 ; i<10 ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			board[i][j].pos_x = i;
			board[i][j].pos_y = j; 	/*This loop writes x and y coordinates.*/
			board[i][j].jump_x = 0;
			board[i][j].jump_y = 0;	
		}
		
		if(i%2==0)
		{	x-=10;
			for(j=0 ; j<10 ; j++)
			{
				board[i][j].data = x;
				board[i][j].type = x;	/*This loop writes the data and the type of each block of the board. (for the even line)*/
				sprintf(board[i][j].text,"%d",x);				
				x++;
			}
			x--;
		}
		
		else
		{
			x-=10;
			for(j=0 ; j<10 ; j++)
			{
				board[i][j].data = x;	/*This loop writes the data and the type of each block of the board. (for the odd line)*/
				board[i][j].type = x;
				sprintf(board[i][j].text,"%d",x);
				x--;
			}
			x++;
		}
		
	}
	
	sprintf(board[0][2].text,"%s","T");	
	sprintf(board[0][7].text,"%s","S{72}");	
	sprintf(board[0][8].text,"%s","S{56}");	
	sprintf(board[0][9].text,"%s","100(Finish)");	
	sprintf(board[1][1].text,"%s","M{94}");	
	sprintf(board[1][5].text,"%s","P");	
	sprintf(board[1][8].text,"%s","B");	
	sprintf(board[2][2].text,"%s","S{68}");		/*These functions writes the text in the text array*/
	sprintf(board[2][5].text,"%s","M{83}");	
	sprintf(board[2][8].text,"%s","T");	
	sprintf(board[3][1].text,"%s","M{77}");	
	sprintf(board[3][4].text,"%s","B");	
	sprintf(board[3][7].text,"%s","S{52}");	
	sprintf(board[4][3].text,"%s","T");	
	sprintf(board[4][6].text,"%s","M{77}");	
	sprintf(board[4][9].text,"%s","S{44}");	
	sprintf(board[5][0].text,"%s","B");	
	sprintf(board[5][2].text,"%s","P");	
	sprintf(board[5][5].text,"%s","S{22}");	
	sprintf(board[6][1].text,"%s","M{52}");	
	sprintf(board[6][5].text,"%s","B");	
	sprintf(board[6][9].text,"%s","T");	
	sprintf(board[7][1].text,"%s","B");	
	sprintf(board[7][5].text,"%s","S{12}");	
	sprintf(board[8][2].text,"%s","P");	
	sprintf(board[8][6].text,"%s","M{28}");	
	sprintf(board[9][3].text,"%s","M{11}");	
	sprintf(board[9][4].text,"%s","S{1}");	
	sprintf(board[9][9].text,"%s","1(Start)");	
	
	
	board[0][2].type = 'T';	
	board[0][7].type = 'S';	
	board[0][8].type = 'S';	
	board[1][1].type = 'M';	
	board[1][5].type = 'P';	
	board[1][8].type = 'B';	
	board[2][2].type = 'S';	
	board[2][5].type = 'M';	
	board[2][8].type = 'T';	
	board[3][1].type = 'M';	
	board[3][4].type = 'B';	
	board[3][7].type = 'S';	
	board[4][3].type = 'T';		/*The necessary characters write in suitable block.*/
	board[4][6].type = 'M';	
	board[4][9].type = 'S';	
	board[5][0].type = 'B';	
	board[5][2].type = 'P';	
	board[5][5].type = 'S';	
	board[6][1].type = 'M';	
	board[6][5].type = 'B';
	board[6][9].type = 'T';	
	board[7][1].type = 'B';	
	board[7][5].type = 'S';	
	board[8][2].type = 'P';	
	board[8][6].type = 'M';	
	board[9][3].type = 'M';	
	board[9][4].type = 'S';	
	
	board[9][4].jump_x = 9;
	board[9][4].jump_y = 9;	
	board[9][3].jump_x = 8;
	board[9][3].jump_y = 0;
	board[8][6].jump_x = 7;
	board[8][6].jump_y = 2;
	board[7][5].jump_x = 8;
	board[7][5].jump_y = 1;
	board[7][1].jump_x = 6;
	board[7][1].jump_y = 3;
	board[6][9].jump_x = 6;		/*The data number writes the suitable block.*/
	board[6][9].jump_y = 4;
	board[6][5].jump_x = 5;
	board[6][5].jump_y = 9;
	board[6][1].jump_x = 4;
	board[6][1].jump_y = 1;
	board[5][5].jump_x = 7;
	board[5][5].jump_y = 8;
	board[5][0].jump_x = 4;
	board[5][0].jump_y = 4;
	board[4][9].jump_x = 5;
	board[4][9].jump_y = 6;
	board[4][6].jump_x = 2;
	board[4][6].jump_y = 6;
	board[4][3].jump_x = 5;
	board[4][3].jump_y = 1;
	board[3][7].jump_x = 4;
	board[3][7].jump_y = 1;	
	board[3][4].jump_x = 2;
	board[3][4].jump_y = 0;
	board[3][1].jump_x = 2;
	board[3][1].jump_y = 6;
	board[2][8].jump_x = 2;
	board[2][8].jump_y = 3;
	board[2][5].jump_x = 1;
	board[2][5].jump_y = 7;
	board[2][2].jump_x = 3;
	board[2][2].jump_y = 2;
	board[1][8].jump_x = 1;
	board[1][8].jump_y = 3;	
	board[1][1].jump_x = 0;
	board[1][1].jump_y = 3;
	board[0][2].jump_x = 1;
	board[0][2].jump_y = 2;
	board[0][7].jump_x = 2;
	board[0][7].jump_y = 1;
	board[0][8].jump_x = 4;
	board[0][8].jump_y = 5;																																		
}

void printBoard(block board[][10])
{
	int i,j;
	for(i=0 ; i<10 ; i++)
	{						/*This function prints the board*/
		for(j=0 ; j<10 ; j++)
		{
			printf("%s\t",board[i][j].text);
		}
		printf("\n\n");
	}
}

int singlePlayer(block board[][10], int x, int y, int counter)
{					/*This function plays a  single player game.*/
	int oldx = x;
	int oldy = y;
	int x_1=0,y_1=0;
	int dice;	
	do{	
		dice = 1+rand()%5;
			
	}while(board[x][y].data+dice>100);
	
	

	if(y-dice>=0&&x%2!=0)
		y-=dice;
	else if(y-dice<0&&x%2!=0)		/*For the movement, x and y coordinates are changed.*/
	{
		x-=1;
		y=dice-y-1;
	}	
	else if(y+dice<=9&&x%2==0)
		y+=dice;
	else if(y+dice>9&&x%2==0)
	{
		x-=1;
		y = 10-((y+dice)%9);
	}	
	x_1=x;
	y_1=y;
	if(board[x][y].type=='S')
	{
		x=board[x_1][y_1].jump_x;
		y=board[x_1][y_1].jump_y;	
	}
	if(board[x][y].type=='M')		/*The movements of special types are determined.*/
	{
		x=board[x_1][y_1].jump_x;
		y=board[x_1][y_1].jump_y;			
	}
	if(board[x][y].type=='T')
	{
		x=board[x_1][y_1].jump_x;
		y=board[x_1][y_1].jump_y;		
	}
			
	if(board[x][y].type=='B')
	{
		x=board[x_1][y_1].jump_x;
		y=board[x_1][y_1].jump_y;	
	}
	if(board[x][y].type=='P')
	{			
		x = oldx;
		y = oldy;
	}
	int a;
	if(board[x][y].data<100)
	{	
		/*If the game is not over, the function is called again.*/
		counter++;	
		counter = singlePlayer(board, x, y, counter);
	}
	printf("\nThe Block Board:%d\tDice:%d  ",board[x][y].data,dice);

	if(board[x][y].data==100)
	{
		counter++;	/*If the game is over, this function returns the counter.*/
		printf("\nIt's done");
		return counter;

	}	
	return counter;
}

void multiplayer(block board[][10])
{
	int player1 = 0,player2 =0;	/*This a kind of multiplayer game function.*/
	printf("Player 1's game:\n");
	player1 = singlePlayer(board,9,9,player1);	/*SinglePlayer function is called for each of players.*/
	printf("\nThe Block Board:1(Start)");
	printf("\n-------------------------------------------------------------------\n");
	printf("Player 2's game:\n");
	player2 = singlePlayer(board,9,9,player2);
	printf("\nThe Block Board:1(Start)");
	printf("\n-------------------------------------------------------------------\n");
	
	printf("\nPlayer 1's move count:%d",player1);
	printf("\nPlayer 2's move count:%d",player2);
	
	if(player1==player2)		/*Winner is determineted.*/
		printf("\nNo winner!\n");
	if(player1<player2)			
		printf("\nWinner is Player 1!\n");
	else
		printf("\nWinner is Player 2!\n");		
	
}
