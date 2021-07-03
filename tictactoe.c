#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "array.c"

// Game Board Constants
#define EMPTY ' '
#define AI 'O'
#define HUMAN 'X'

// Game State Constants
#define PLAYING 0
#define TIE 1
#define O_WIN 2
#define X_WIN 3

// Function declarations
void humanMove(char board[]);
void aiMove(char board[]);
void drawBoard(char board[]);
void clearBoard(char board[]);
int getState(char board[]);
int getScore(char board[], int depth);
Array minimax(char board[], int depth, char player);

int main()
{
	printf("####################\n");
	printf("# TIC TAC TOE A.I. #\n");
	printf("####################\n");
	
	char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	drawBoard(board);
	clearBoard(board);
	
	int turnTakingPlayer;
	char choice;
	
	repeatInput:
	printf("## Do you want to go first? (Y/N) : ");
	scanf("%c", &choice);
	putchar('\n');
	choice = toupper(choice);
	
	if(choice == 'Y')
        turnTakingPlayer = HUMAN;
    else if(choice == 'N')
        turnTakingPlayer = AI;
    else
	{
		puts("?? Wrong Input!");
		goto repeatInput;
		
	}
	
	int turn;
	for(turn=1; turn<=9 && getState(board) == PLAYING; turn++)
	{
		if(turnTakingPlayer == HUMAN)
		{
			humanMove(board);
			turnTakingPlayer = AI;
		}
		else
		{
			aiMove(board);
			turnTakingPlayer = HUMAN;
		}
	}

	if(getState(board) == TIE)
		printf("== This match was a TIE. I will see you next time.\n");
	else if(getState(board) == AI)
		printf("×× You lost the match. Hmm it was certain.\n");
	else if(getState(board) == HUMAN)
		printf("** WHAT!? You won the match!! I thought I was unbeatable.\n");
	
	putchar('\n');
	main();
	return 0;
}

void humanMove(char board[])
{
	int pos = 0;
	do{
		printf("## Where do you want to place (X)? (1-9) : ");
		scanf("%d", &pos);
		
		if(board[pos-1] != EMPTY && pos != 99)
			puts("?? Wrong Input!");

	}while(board[pos-1] != EMPTY && pos != 99);
	
	if(pos != 99)
		board[pos - 1] = HUMAN;
	else
	{
		Array bestScore;
		bestScore = minimax(board, 0, HUMAN);
		board[bestScore.array[1]] = HUMAN;
	}
	
	drawBoard(board);
}

void aiMove(char board[])
{
	printf("$$ My turn :\n");
	Array bestScore;
	bestScore = minimax(board, 0, AI);
	board[bestScore.array[1]] = AI;
	drawBoard(board);
}

void drawBoard(char board[])
{
	putchar('\n');
	printf("+-----+-----+-----+\n");
	printf("|  %c  |  %c  |  %c  |\n", board[0], board[1], board[2]);
    printf("+-----+-----+-----+\n");
	printf("|  %c  |  %c  |  %c  |\n", board[3], board[4], board[5]);
	printf("+-----+-----+-----+\n");
	printf("|  %c  |  %c  |  %c  |\n", board[6], board[7], board[8]);
	printf("+-----+-----+-----+\n");
	putchar('\n');
}

void clearBoard(char board[])
{
	unsigned i;
	for(i=0; i<9; i++)
		board[i] = EMPTY;
}

int getState(char board[])
{
	unsigned wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	
	unsigned i;
	for(i=0; i<8; i++)
		if(board[wins[i][0]] != EMPTY && board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
			return board[wins[i][0]];
	
	for(i=0; i<9; i++)
		if(board[i] == EMPTY)
			return PLAYING;
	
	return TIE;
}

int getScore(char board[], int depth)
{
	if(getState(board) == AI)
		return  10 - depth;
	else if(getState(board) == HUMAN)
		return -10 - depth;
	else
		return 0;
}

Array minimax(char board[], int depth, char player)
{
	depth++;
	
	Array score, bestScore;
	createArray(&bestScore, 2);
	
	if(getState(board) != PLAYING)
	{
		bestScore.array[0] = getScore(board, depth);
		bestScore.array[1] = 0;
		return bestScore;
	}
	
	if(player == AI)
		bestScore.array[0] = -1000;
	else
		bestScore.array[0] =  1000;
	
	unsigned i;
	for(i=0; i<9; i++)
	{
		if(board[i] == EMPTY)
		{
			board[i] = player;
			
			if(player == AI)
			{
				score = minimax(board, depth, HUMAN);
			
				if(score.array[0] > bestScore.array[0])
				{
					bestScore.array[0] = score.array[0];
					bestScore.array[1] = i;
				}
			}
			else
			{
				score = minimax(board, depth, AI);
			
				if(score.array[0] < bestScore.array[0])
				{
					bestScore.array[0] = score.array[0];
					bestScore.array[1] = i;
				}
			}
			board[i] = EMPTY;
		}
	}
    return bestScore;
}
