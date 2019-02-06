#include<stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty, board} piece;
typedef enum {white = 10, black = 20} player;

void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]); /*prototypes of functions were created.*/
void display_board(piece board[][8]);
int check_empty_walk_black(piece board[][8], int from_x, int from_y, int to_x, int to_y);
int check_multiple_jump_black(piece board[][8]);
int check_move_kingB(piece board[][8], int from_x, int from_y, int to_x, int to_y);
int check_empty_walk_white(piece board[][8], int from_x, int from_y, int to_x, int to_y);
int check_multiple_jump_white(piece board[][8]);
int check_move_kingW(piece board[][8], int from_x, int from_y, int to_x, int to_y);
void game_1_board(piece board[][8]);
void game_2_board(piece board[][8]);

void sample_game_1();
void sample_game_2();

int main()
{
	player p;
	int from_x, from_y, to_x, to_y, i=2;
	piece board[8][8];
/*	init_board(board);		//This is a kind of multiplayer draughts game.
  	display_board(board);	
  	move(board, from_x, from_y, to_x, to_y,  p);
*/

/*
	sample_game_1();	*/	
	sample_game_2();  /*These are 2 famous sample game*/
	
	
	return 0;
}
void game_1_board(piece board[][8])
{
	piece white_man = 'w';
	piece blackman = 'b';
	piece empty = '-';
	piece black_king = 'B';
	piece white_king = 'W';
	int i,j;
	for(i=0 ; i<8 ; i++)
	{	
		for(j=0 ; j<8 ; j++)
		{						/*For the first game, a game board was formed.*/
			board[i][j] = empty;
		}
	}	
	
	board[3][0] = blackman;
	board[3][1] = blackman;
	board[2][1] = blackman;
	board[2][3] = blackman;
	board[2][5] = blackman;
	board[2][7] = blackman;
	board[3][5] = blackman;
	board[3][7] = blackman;
	board[4][1] = white_man;
	board[4][3] = white_man;
	board[4][5] = white_man;
	board[4][7] = white_man;
	board[5][0] = white_man;
	board[5][1] = white_man;
	board[5][5] = white_man;
	board[5][7] = white_man;
	
}

void game_2_board(piece board[][8])
{
	piece white_man = 'w';
	piece blackman = 'b';
	piece empty = '-';
	piece black_king = 'B';
	piece white_king = 'W';
	int i,j;
	for(i=0 ; i<8 ; i++)	/*The game board for the second game was created.*/
	{	
		for(j=0 ; j<8 ; j++)
		{
			board[i][j] = empty;
		}
	}	

	i=1;
	for(j=2 ; j<6 ; j++)
	{
		board[i][j]=blackman;
	}	
	i=2;
	for(j=1 ; j<5 ; j++)
	{
		board[i][j]=blackman;
	}
	board[2][6] = blackman;
	board[2][7] = blackman;
	board[3][0] = blackman;
	board[3][2] = blackman;
	board[3][5] = blackman;
	board[3][7] = blackman;
	board[4][5] = blackman;
	board[5][2] = blackman;
	i=4;
	for(j=2 ; j<5 ; j++)
	{
		board[i][j]=white_man;
	}
	i=5;
	for(j=2 ; j<5 ; j++)
	{
		board[i][j]=white_man;
	}
	i=6;
	for(j=2 ; j<6 ; j++)
	{
		board[i][j]=white_man;
	}		
	board[5][0]=white_man;
	board[4][6]=white_man;
	board[4][7]=white_man;
	board[5][6]=white_man;
	board[5][7]=white_man;
	board[5][1]=blackman;
	
}
void init_board(piece board[][8])
{
	piece white_man = 'w';
	piece blackman = 'b';
	piece empty = '-';
	piece black_king = 'B';
	piece white_king = 'W';
	
	int i,j;
	for(i=0 ; i<8 ; i++)
	{	
		for(j=0 ; j<8 ; j++)
		{
			board[i][j] = empty;
		}
	}
	
	for(i=1 ; i<3 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			board[i][j] = blackman;
		}
		
	}	

	for(i=5 ; i<7 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			board[i][j] = white_man;
		}
		
	}	
	
}

void display_board(piece board[][8])
{
	
	int i, j, a=1;
	printf("  12345678\n");
	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)	/*A function was created to show the game board.*/
		{
			if(j==0)
			{
			printf("%d %c",a,board[i][j]);
			a++;
			}
			else
			printf("%c",board[i][j] );
			
		}
		printf("\n");
	}	
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p)
{
	int i,j, error=0;
	from_x = 0;
	from_y = 0;
	int a = 0;	
	while(check_end_of_game(board)==-1)
	{
		a++;
	/*if error = 1 => white plays*/
	/*if error = 2 => black plays*/
		
		if(a%2==0)
			p = 10;
		else
			p = 20;	
			
		if(p == 10)
		{
			while(board[from_x-1][from_y-1]!='w')
			{		/*A loop was created for a white man.*/
							
				printf("Enter the white current coordinates: ");
				scanf("%d %d", &from_x, &from_y);
				if(board[from_x-1][from_y-1]!='w')
					printf("False Selection!");
				else
				{	
					printf("Enter the next coordinates: ");
					scanf("%d %d", &to_x, &to_y);	
					while(check_empty_walk_white(board, from_x, from_y, to_x, to_y)==0)
					{
						printf("False Selection!");	
						printf("Enter the next coordinates: ");
						scanf("%d %d", &to_x, &to_y);							
					}
				}
			}
			if(check_empty_walk_white(board, from_x, from_y, to_x, to_y)==2)
			{	
				error = 2;
				board[from_x-2][from_y-1] = '-'; 
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y-1] = '-';
				
				if(check_multiple_jump_white(board)==2)
				{
					error = 1;
				}

			}

			
			if(check_empty_walk_white(board, from_x, from_y, to_x, to_y)==3)
			{	
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y] = '-';			
				error = 2;

				board[from_x-1][from_y-1] = '-';				
				if(check_multiple_jump_white(board)==3)
						error = 1;				
			}/*to the right.*/
			
			if(check_empty_walk_white(board, from_x, from_y, to_x, to_y)==4)
			{	
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];			
				board[from_x-1][from_y-2] = '-'; 
				error = 2;
				
				board[from_x-1][from_y-1] = '-';				
				if(check_multiple_jump_white(board)==4)
						error = 1;			
			}
			if(to_x-from_x<2&&to_y-from_y<2&&to_y-from_y>-2&&to_x-from_x>-2)
			{						
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y-1] = '-';
				error = 2;
			}
			printf("\nerror:%d\n",error);			
			display_board(board);

				
		}
		
		else
		{	while(board[from_x-1][from_y-1]!='b')
			{
				/*A loop was created for a black man.*/		
				printf("Enter the black current coordinates: ");
				scanf("%d %d", &from_x, &from_y);
				if(board[from_x-1][from_y-1]!='b')
					printf("False Selection!");
				else
				{	
					printf("Enter the next coordinates: ");
					scanf("%d %d", &to_x, &to_y);	
					while(check_empty_walk_black(board, from_x, from_y, to_x, to_y)==0)
					{
						printf("False Selection!");	
						printf("Enter the next coordinates: ");
						scanf("%d %d", &to_x, &to_y);							
					}
				}
			}
			if(check_empty_walk_black(board, from_x, from_y, to_x, to_y)==2)
			{	
				error = 1;
				board[from_x][from_y-1] = '-'; 
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y-1] = '-';
				
				if(check_multiple_jump_black(board)==2)
						error = 2;				

			}
			else
				error = 1;	

			
			if(check_empty_walk_black(board, from_x, from_y, to_x, to_y)==3)
			{	
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y] = '-';			
				error = 1;

				board[from_x-1][from_y-1] = '-';				
				if(check_multiple_jump_black(board)==3)
						error = 2;				
			}/*To the right.*/

			if(check_empty_walk_black(board, from_x, from_y, to_x, to_y)==4)
			{	
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];			
				board[from_x-1][from_y-2] = '-'; 
				error = 1;
				
				board[from_x-1][from_y-1] = '-';				
				if(check_multiple_jump_black(board)==4)
						error = 2;			
			}

			if(to_x-from_x<2&&to_y-from_y<2&&to_x-from_x>-2&&to_y-from_y>-2)
			{
				board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
				board[from_x-1][from_y-1] = '-';
			}
			for(i=0 ; i<8 ; i++)
			{
				if(board[7][i]=='b')
					board[7][i] = 'B';
			}
			printf("\nerror:%d\n",error);
			display_board(board);	
		}
	}
}

int check_empty_walk_black(piece board[][8], int from_x, int from_y, int to_x, int to_y)
{
	int i,j;

	if(board[to_x-1][to_y-1]=='-'&&(board[from_x-1][from_y-2]!='w')&&(board[from_x-1][from_y]!='w')&&((board[from_x][from_y-1]!='w')))
	{
		if(to_x-from_x>1||to_y-from_y>1)
		{
			return 0;
		}
		else 
		{
			if((to_x-from_x==1&&to_y==from_y)||(to_x==from_x&&to_y-from_y==1)||(to_x==from_x&&to_y-from_y==-1))
				return 1;
			else	
				return 0;
		}
	}

	if(board[from_x][from_y-1]=='w'&&board[from_x+1][from_y-1]=='-')
	{ 
	/*ileri yeme*/
		if(to_x-from_x>2)
		{
			return 0;
		}		
			
		if(to_x-1==from_x+1&&to_y-1==from_y-1)
		{
			return 2;
		}
			
		return 0;	
	}	

	if(board[from_x-1][from_y]=='w'&&board[from_x-1][from_y+1]=='-')
	{ 	
		if(to_y-from_y>2)
		{
			return 0;
		}	
	/*To jump the right.*/
		if(to_x-1==from_x-1&&to_y-1==from_y+1)
			return 3;
			
		return 0;	
	}

	if(board[from_x-1][from_y-2]=='w'&&board[from_x-3][from_y-1]=='-')
	{ /*To jump the left.	*/
		if(to_y-from_y<-2)
		{
			return 0;
		}
		if(to_x-1==from_x-1&&to_y-1==from_y-3)
			return 4;
			
		return 0;	
	}	



		return 1;	
}

int check_multiple_jump_black(piece board[][8])
{ 	
	int i,j;

	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{	
			if(board[i][j]=='w'&&board[i-1][j]=='b'&&board[i+1][j]=='-')
				return 2;			//ileri
				
			if(board[i][j]=='w'&&board[i][j-1]=='b'&&board[i][j+1]=='-')
			{
				return 3; /*To the right.*/
				
			}
			
			if(board[i][j]=='w'&&board[i][j+1]=='b'&&board[i][j-1]=='-')
			{	
				return 4; /*To the left.*/
			}
		}
	}

	return 0;
}

int check_move_kingB(piece board[][8], int from_x, int from_y, int to_x, int to_y)
{
	int i,j;
	if(from_y-1==to_y-1&&to_x-1>from_x-1)
	{	/* To the bottom.*/
		for(i=from_x ; i<to_x-1 ; i++)
		{
			if(board[i][to_y-1]!='-')
				return 0;
		}
	}
	
	if(from_y-1==to_y-1&&to_x-1<from_x-1)
	{	/*To the next*/
		for(i=from_x ; i>to_x-1 ; i--)
		{
			if(board[i][to_y-1]!='-')
				return 0;
		}
	}
		
	if(from_x-1==to_x-1&&to_y-1>to_x-1)
	{	/*To the right.*/
		for(i=from_y ; i<to_y-1 ; i++)
		{
			if(board[to_x-1][i]!='-')	
				return 0;
		}
	}
	
	if(from_x-1==to_x-1&&to_y-1<to_x-1)
	{	/*To the left.*/
		for(i=from_y ; i>to_y-1 ; i)
		{
			if(board[to_x-1][i]!='-')	
				return 0;
		}
	}	
	
	
	return 1;	
}

int check_empty_walk_white(piece board[][8], int from_x, int from_y, int to_x, int to_y)
{	
	if(board[from_x-2][from_y-1]=='b'&&board[from_x-3][from_y-1]=='-')
	{ 
		if(to_x-from_x<-2)
		{
			return 0;
		}		
			
		if(to_x+1==from_x-1&&to_y-1==from_y-1)
			return 2;
			
		return 0;	
	}	
	if(board[from_x-1][from_y]=='b'&&board[from_x-1][from_y+1]=='-')
	{ 	
		if(to_y-from_y>2)
		{
			return 0;
		}		
	/*To jump the right.*/
		if(to_x-1==from_x-1&&to_y-1==from_y+1)
			return 3;
			
		return 0;	
	}

	if(board[from_x-1][from_y-2]=='b'&&board[from_x-1][from_y-3]=='-')
	{ /*To jump the left.*/
		if(to_y-from_y<-2)
		{
			return 0;
		}

		if(to_x-1==from_x-1&&to_y-1==from_y-3)
			return 4;
	
		return 0;	
	}	

	if(board[to_x-1][to_y-1]=='-'&&(board[from_x-1][from_y-2]!='b')&&(board[from_x-1][from_y]!='b'))
	{
		if(to_x-from_x<-1||to_y-from_y<-1||to_x-from_x>0)
		{
			return 1;
		}		
		else
		{
			if((to_x-from_x==-1&&to_y==from_y)||(to_x==from_x&&to_y-from_y==1)||(to_x==from_x&&to_y-from_y==-1))
				return 1;
			else
				return 0;	
		}
	}	
		
	return 1;
	
}

int check_multiple_jump_white(piece board[][8])
{ 	
	int i,j;

	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{	
			if(board[i][j]=='b'&&board[i+1][j]=='w'&&board[i-1][j]=='-')
			{
				return 2;			/*To the next.*/
			}
			if(board[i][j]=='b'&&board[i][j-1]=='w'&&board[i][j+1]=='-')
			{
				return 3; /*To the right.*/
				
			}
			
			if(board[i][j]=='b'&&board[i][j+1]=='w'&&board[i][j-1]=='-')
			{	
				return 4; /*To the left.*/
			}
		}
	}

	return 0;
}

int check_move_kingW(piece board[][8], int from_x, int from_y, int to_x, int to_y)
{
	int i,j;
	if(from_y-1==to_y-1&&to_x-1>from_x-1)
	{		/*To the next.*/
		for(i=from_x ; i<to_x-1 ; i++)
		{
			if(board[i][to_y-1]!='-')
				return 0;
		}
	}
	
	if(from_y-1==to_y-1&&to_x-1<from_x-1)
	{	/*The the bottom.*/
		for(i=from_x ; i>to_x-1 ; i--)
		{
			if(board[i][to_y-1]!='-')
				return 0;
		}
	}
		
	if(from_x-1==to_x-1&&to_y-1>to_x-1)
	{	/*To the left.*/
		for(i=from_y ; i<to_y-1 ; i++)
		{
			if(board[to_x-1][i]!='-')	
				return 0;
		}
	}
}

int check_end_of_game(piece board[][8])
{
	int counterB=0, counterW=0, i,j;
	for(i=0 ; i<8 ; i++)
	{					/*This function was written for game end.*/
		for(j=0 ; j<8 ; j++)
		{
			if(board[i][j]=='w'||board[i][j]=='W')
				counterW++;
			if(board[i][j]=='b'||board[i][j]=='B')
				counterB++;				
		}
	}
	if(counterB==0)
	{
		printf("White is winner!");
		return white;
	}
	if(counterW==0)
	{
		printf("Black is winner!");
		return black;
	}	
	
	return -1;
}
void sample_game_1()
{
	piece board[8][8];	/*The function of the first game was written.*/
	game_1_board(board);
	display_board(board);
	board[5][7] = '-';
	board[5][6] = 'w';
	display_board(board);
	board[3][7] = '-';
	board[4][7] = '-';
	board[5][7] = 'b';
	display_board(board);
	board[5][5] = '-';
	board[5][4] = 'w';
	display_board(board);
	board[3][5] = '-';
	board[4][5] = '-';
	board[5][5] = 'b';
	display_board(board);
	board[5][5] = '-';
	board[5][4] = '-';
	board[5][3] = 'b';
	display_board(board);
	board[4][1] = '-';
	board[4][0] = 'w';
	display_board(board);
	board[5][7] = '-';
	board[5][6] = '-';
	board[5][5] = 'b';
	display_board(board);
	board[4][0] = '-';
	board[3][0] = '-';
	board[2][0] = 'w';
	display_board(board);
	board[2][0] = '-';
	board[2][1] = '-';
	board[2][2] = 'w';
	display_board(board);
	board[2][2] = '-';
	board[2][3] = '-';
	board[2][4] = 'w';
	display_board(board);
	board[2][4] = '-';
	board[2][5] = '-';
	board[2][6] = 'w';
	display_board(board);
		
	
}

void sample_game_2()
{
	piece board[8][8];
	game_2_board(board);
	display_board(board);		
	board[4][3] = '-';
	board[3][3] = 'w';
	display_board(board);
	board[4][5] = '-';
	board[4][3] = 'b';
	board[4][4] = '-';
	display_board(board);
	board[4][3] = '-';
	board[4][1]	= 'b';
	board[4][2] = '-';
	display_board(board);		/*The function of the second game was written.*/
	board[3][3] = '-';
	board[3][1] = 'w';
	board[3][2] = '-';
	display_board(board);
	board[3][1] = '-';
	board[1][1] = 'w';
	board[2][1] = '-';
	display_board(board);
	board[1][2] = '-';
	board[1][1] = '-';
	board[1][0] = 'b';
	display_board(board);
	board[5][3] = '-';
	board[4][3] = 'w';
	display_board(board);
	board[5][1] = '-';
	board[5][2] = '-';
	board[5][3] = 'w';
	display_board(board);
	board[5][3] = '-';
	board[5][4] = '-';
	board[5][5] = 'w';	
	display_board(board);
	board[5][5] = '-';
	board[6][5] = '-';
	board[7][5] = 'B';		
	display_board(board);
	board[4][3] = '-';
	board[3][3] = 'w';
	display_board(board);
	board[2][3] = '-';
	board[3][3] = '-';
	board[4][3] = 'b';		
	display_board(board);
	board[5][6] = '-';
	board[5][5] = 'w';
	display_board(board);
	board[7][5] = '-';
	board[5][5] = '-';
	board[4][5] = 'B';	
	display_board(board);
	board[4][6] = '-';
	board[4][5] = '-';
	board[4][4] = 'w';	
	display_board(board);
	board[4][4] = '-';
	board[4][3] = '-';
	board[4][2] = 'w';	
	display_board(board);
	board[4][2] = '-';
	board[4][1] = '-';
	board[4][0] = 'w';	
	display_board(board);
	board[4][0] = '-';
	board[3][0] = '-';
	board[2][0] = 'w';	
	display_board(board);
	board[2][0] = '-';
	board[1][0] = '-';
	board[0][0] = 'W';	
	display_board(board);
								
}


