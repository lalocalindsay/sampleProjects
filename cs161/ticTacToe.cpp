/****************************************************************************************
Author: Lindsay Tucker
Date created: 16Nov2014
Date last modified: 14Nov2014
Program Filename:  ticTacToe.cpp
Description/overview: 
This is a 2 player game of TTT.  It will use a 3x3 array
as a game board. The users will enter how many games they are to play
on the command line (if no int is indicated, the default will be one game).
Every game will switch which player gets to go
first. Each player will enter the coordinates (two ints separated by a space)
of their move.  If a space has already been taken, the player will
be prompted to enter another location. The board will update after every move. The players will 
also be notified if a player has made a winning move, or if they've run out of 
turns (tie). The game score tally will be displayed along with a message of
who the final champion is. 

INPUT: 
		-command line: number of games to play
		-each player will take turns entering coordinates for their move
		

		
	
OUTPUT: 
the program will output the following:
		whose turn it is
		what # turn it is
		the coordinates entered for each player
		updated game board
		number of games remaining
		score
		tie
		overall champion							
****************************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
  
using namespace std;

//Global variables
const int ROW =3;
const int COL =3;
int player1_score=0; //update from function 
int player2_score=0;  //update from function 


//Function prototypes
void printEmptyGameBoard ();
int turnKeeper(int turn, int game_counter); 
char insertXorO(int turn_holder);
int checkWinner (char game_array[ROW][COL]);  
void reset(char game_array [ROW][COL]);


int main(int argc, char *argv[])
{
	
	int games=1; //default 1 if no command line is entered
	
	
	if (argc <= 1) 
    {
        cout << "You didn't specify the number of games, you'll just play once." << endl;
	}
	
	else
	{
			cout<<"You will play Tic Tac Toe "<<argv[1]<< " times:"<<endl;
			games	= atoi (argv[1]); //convert  c-string values from argv to int
	}
	
	
	char game_array[ROW][COL];  //to be filled  during game and then reset at the beginning of every game
	
	
	//display game board
	printEmptyGameBoard ();
	
	//Display game instructions
	//Player 1 (X)
	//Player 2 (O)
	cout<< "-------------| TIC | TAC | TOE|-------------"<<endl;
	cout<< "PLAYERS 1 & 2, YOUR GAME BOARD WILL BE A 3X3 ARRAY."<<endl<<endl;
	cout<< "YOU WILL INDICATE YOUR MOVE BY ENTERING COORDINATES. "<<endl;
	cout<< "ROWS AND COLUMNS ARE NUMBERED 0-2."<<endl;
	cout<< "FOR EXAMPLE [0] [0] WILL INDICATE A MOVE IN THE TOP LEFT "<<endl;
	cout<< "OF THE GAME BOARD." <<endl<<endl<<endl;
	
	cout<<"PLAYER 1, YOU ARE (Os) & PLAYER 2, YOU ARE (Xs)."<<endl;
	
	reset(game_array); 

	int game_counter=0;
	
	do
	{
			////////////////////////////////////////////  GAME  START /////////////////////////////////////////
			int turn = 0;
			while (turn < 9) // 0, 1, 2,  3,  4,  5,  6,  7, 8
			{
					

					//determines whose turn
					int turn_holder =turnKeeper( turn, game_counter);
							//cout<<"\nTurn holder: " << turn_holder<<endl; //TESTING
							//cout<< insertXorO(turn_holder)<<endl;  //TESTING
						
	
					///////////////////////////////  Get player input  //////////////////////////////////////////////////////////
					int row_move, col_move;
					do
					{
							
							
							cout<< turn<<") Enter your move (two integers separated by a space): "<<endl;
							cin>> row_move;	//help from tutor Andrew Rice
							cin>> col_move;
							cin.ignore(10000, '\n');
							cin.clear();
							
							
							/*
							while (!cin) //INPUT VALIDATION NOT WORKING
							{
									cout<< turn<<") Enter your move (two integers separated by a space): "<<endl;
									cin>> row_move;	//help from tutor Andrew Rice
									cin>> col_move;
									cin.ignore(10000, '\n');
									cin.clear();
						
							}  
							*/
							
							cout << "row_move and col_move are: " << row_move << "  and   " << col_move << endl;
					
					}while (game_array[row_move][col_move] != '*'); //If == ' * ', it won't update game_array //can't remember why this is here
	

	
					///////////////////////////   Fill game array location    ///////////////////////////////		
					//update game_array w/ X or O depending on whose turn
					if (game_array[row_move][col_move] == '*')
							game_array[row_move][col_move] =  insertXorO(turn_holder);
					
					cout<<endl;
					
					//print updated game array
					for (int i=0; i<ROW; i++)
					{
							for (int j=0; j<COL; j++)
							{							
									cout<<game_array[i][j]; //TESTING
							}
							cout<<endl;
					}
					
					cout<<endl;
					
					//check if a winner (add to  player score from function, end game if 1 returned from function)	
					//return an int in order to break current game
					int winner=0;
					winner = checkWinner (game_array); 
							//cout<< "Winner: " <<winner<< endl; //TESTING
					if (winner >=1) //breaks out of the game that was just won
					{
							break;
					}	
					
					cout<<endl;
	
	
					turn ++; // at end of game
					if (turn == 9) //game over
					{	
							cout<< "THIS GAME WAS A DRAW"<<endl;
							break;	
					}
			} //end of game (while turn <9)
			//////////////////////////////////////////////  GAME END  ////////////////////////////////////////////
			game_counter++;
			cout<<endl<< endl;
			
			if ((game_counter) < games)
			{
					cout<< "NEXT GAME ( "<< game_counter+1 <<" of "<<games<<") " <<endl;
					reset(game_array); 
			}
			
			cout<< "Player 1 score: "<< player1_score<<endl; //TESTING
			cout<< "Player 2 score: "<< player2_score<<endl<<endl; //TESTING
			
			if ((game_counter) >= games)
			{
					if (player1_score > player2_score)
						cout<< "PLAYER 1, YOU'RE THE OVERALL CHAMPION!"<<endl;
					if (player2_score > player1_score)
						cout<< "PLAYER 2, YOU'RE THE OVERALL CHAMPION!"<<endl;
					else if (player1_score == player2_score)
						cout<< "PLAYER 1 & PLAYER 2, YOU ARE TIED!"<<endl;
			}

			//reset(game_array); //move 
	
	} while (game_counter<games); //end of # of games
	
	
	
	return 0;
}


/******************************************************************************
					This function prints an empty game board
 ******************************************************************************/

void printEmptyGameBoard () 
{
	char empty_game_board [3][3];
	
	for (int i=0; i<ROW; i++)
	{
			for (int j=0; j<COL; j++)
			{
					empty_game_board[i][j] = '*';
					cout<<empty_game_board[i][j];
			}
	cout<<endl;
	}
	cout<<endl;

}

 /******************************************************************************
						This function determines whose turn it is
 ******************************************************************************/

 int turnKeeper(int turn, int game_counter)
 {
		if (game_counter%2 ==0)
		{
				if (turn %2 ==0)
				{
						cout<< "Player 1 (X), your turn:"<<endl;
						return 1;
				}
				else 
				{
						cout<< "Player 2 (O), your turn:"<<endl;
						return 2;
				}
		}
		else  
		{
				if (turn %2 ==0)
				{
						cout<< "Player 2 (O), your turn:"<<endl;

						return 2;
				}
				else 
				{
						cout<< "Player 1 (X) your turn:"<<endl;
						return 1;
				}
		}
 
 }
 
 
 
  /******************************************************************************
			This function determines if an X or O goes to game_array
 ******************************************************************************/
char insertXorO(int turn_holder)
{
		char player_1;
		char player_2;
		
		if (turn_holder ==1) //player 1
		{
				player_1 = 'X';
				//cout<< "Function: insertxOrO Player 1: "<< player_1<<endl; //TESTING
				return player_1;
		}					
		if (turn_holder==2) //player 2
		{
				player_2 = 'O';
				//cout<< "Function: insertxOrO Player 2: "<< player_2<<endl; //TESTING
				return player_2;		
		}							
		
}

/******************************************************************************
	This function checks for winner and updates player score (global)
 ******************************************************************************/

int checkWinner (char game_array[][COL]) //send gameArray after every turn, and turn holder
 {
		//row 0 (X)
		if ((game_array[0][0] == 'X' ) && (game_array[0][1]=='X') && (game_array[0][2]=='X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//row 1 (X)
		if ((game_array[1][0] == 'X' ) && (game_array[1][1]=='X') && (game_array[1][2]=='X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//row 2 (X)
		if ((game_array[2][0] == 'X' ) && (game_array[2][1]=='X') && (game_array[2][2]=='X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		
		//diagonal top left to bottom right (X)
		if ((game_array[0][0] == 'X' ) && (game_array[1][1]=='X') && (game_array[2][2]=='X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//diagonal bottom left to top right (X)
		if ((game_array[2][0] == 'X' ) && (game_array[1][1]=='X') && (game_array[0][2]=='X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//col 0 (X)
		if ((game_array[0][0] == 'X' ) && (game_array[1][0]== 'X') && (game_array[2][0]== 'X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//col 1 (X)
		if ((game_array[0][1] == 'X' ) && (game_array[1][1]== 'X') && (game_array[2][1]== 'X') )
		{
				cout<< "Player 1: You're a winner!"<<endl;
				player1_score++;
				return 1;
		}
		
		//col 2 (X)
		if ((game_array[0][2] == 'X' ) && (game_array[1][2]== 'X') && (game_array[2][2]== 'X') )
		{
				cout<< "Player 1: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		//add all other lines for O
		//row 0 (O)
		if ((game_array[0][0] == 'O' ) && (game_array[0][1]=='O') && (game_array[0][2]=='O') )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		//row 1 (O)
		if ((game_array[1][0] == 'O' ) && (game_array[1][1]== 'O' ) && (game_array[1][2]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player1_score++;
				return 1;
		}
		
		//row 2(O)
		if ((game_array[2][0] == 'O' ) && (game_array[2][1]== 'O' ) && (game_array[2][2]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		
		//diagonal top left to bottom right (O)
		if ((game_array[0][0] == 'O') && (game_array[1][1]== 'O' ) && (game_array[2][2]== 'O') )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		//diagonal bottom left to top right (O)
		if ((game_array[2][0] == 'O') && (game_array[1][1]== 'O' ) && (game_array[0][2]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		//col 0(O)
		if ((game_array[0][0] == 'O' ) && (game_array[1][0]== 'O' ) && (game_array[2][0]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		//col 1(O)
		if ((game_array[0][1] == 'O' ) && (game_array[1][1]== 'O' ) && (game_array[2][1]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl;
				player2_score++;
				return 1;
		}
		
		//col 2(O)
		if ((game_array[0][2] == 'O' ) && (game_array[1][2]== 'O' ) && (game_array[2][2]== 'O' ) )
		{
				cout<< "Player 2: You're a winner!"<<endl; 
				player2_score++;
				return 1;
		}
		
		
		
		else 
			return 0;

 }

 
/******************************************************************************
								This function resets board
 ******************************************************************************/

 void reset(char game_array [][COL]) 
 {
 //RESET GAME BOARD: fill w/ asterisks
	for (int i=0; i<ROW; i++)
	{
			for (int j=0; j<COL; j++)
			{
					game_array[i][j] = '*';
					cout<<game_array[i][j]; //TESTING
			}
	cout<<endl;
	}
 
 }

 