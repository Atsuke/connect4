//***************************************************
// Filename: connect_cli.c
//
// Author: 	YOUR NAME(S)
//			Jag Nandigam
//***************************************************

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "connect_game.h"

// function declarations
void getGameInfo(int *board_size, int *connect_length, int *start_player, char *popout);
void displayGameInfo(int board_size, int connect_length, int start_player, char popout);
void playGame(int board_size, int connect_length, int start_player, char popout);

int main(int argc, char *argv[])
{
	int board_size, connect_length, start_player;
	char popout;
	
	// validate command-line arguments, if any provided
	bool args_valid = true;
	if (argc == 5) {
		board_size = atoi(argv[1]);
		connect_length = atoi(argv[2]);
		start_player = atoi(argv[3]);
		popout = tolower(argv[4][0]);
		if (board_size < 8 || board_size > 10 ||
				connect_length < 4 || connect_length > 6 ||
				start_player < 1 || start_player > 2 ||
				(popout != 'y' && popout != 'n')) {
			printf("Command-line arguments missing or invalid. Getting game info interactively...\n");
			args_valid = false;
		}
	} else {
		printf("Command-line arguments missing or invalid. Getting game info interactively...\n");
		args_valid = false;
	}
	
	printf("Welcome to Connect Four Game!!!\n");
	if (!args_valid) {
		getGameInfo(&board_size, &connect_length, &start_player, &popout);
	}
	
	displayGameInfo(board_size, connect_length, start_player, popout);
	
	playGame(board_size, connect_length, start_player, popout);
	
	return 0;
}

void getGameInfo(int *board_size, int *connect_length, int *start_player, char *popout)
{
	do {
		printf("Enter the board size (8 - 10): ");
		scanf("%d", board_size);
		if (*board_size < 8 || *board_size > 10) {
			printf("Invalid board size. Try again...\n");
		}
	} while (*board_size < 8 || *board_size > 10);
	
	do {
		printf("Enter the connect length (4 - 6): ");
		scanf("%d", connect_length);
		if (*connect_length < 4 || *connect_length > 6) {
			printf("Invalid connect length. Try again...\n");
		}
	} while (*connect_length < 4 || *connect_length > 6);	
	
	do {
		printf("Player to start the game (1 or 2)? ");
		scanf("%d", start_player);
		if (*start_player < 1 || *start_player > 2) {
			printf("Invalid player number. Try again...\n");
		}
	} while (*start_player < 1 || *start_player > 2);
	
	do {
		printf("Enable PopOut option (y/n)? ");
		scanf(" %c", popout);
		*popout = tolower(*popout);
		if (*popout != 'y' && *popout != 'n') {
			printf("Invalid input. Try again...\n");
		}
	} while (*popout != 'y' && *popout != 'n');
}

void displayGameInfo(int board_size, int connect_length, int start_player, char popout)
{
	printf("\nBoard Size: %d x %d\n", board_size, board_size);
	printf("Connect Length: %d\n", connect_length);
	printf("PopOut Option: %s\n", popout == 'y' ? "ON" : "OFF");
	printf("Start Player: %d\n\n", start_player);
}

void nextPlayer(int currentPlayer){
    if(currentPlayer == 1){
        currentPlayer = 2;
    }else{
        currentPlayer = 1;
    }
}

void playGame(int board_size, int connect_length, int start_player, char popout)
{
    int currentPlayer = start_player;
    int turn = 0;
    char poppin;
    int dropCol;
	int board[board_size][board_size];

	initializeBoard(board_size, board_size, board);
	printBoard(board_size, board_size, board);

	while(isWinByPlayer(board_size, board_size, board, connect_length, currentPlayer) == false && isBoardFull(board_size, board_size, board) == false){

	    if(turn > 0 && popout == 'y'){
	        printf("Player %i would you like to pop?\n" , currentPlayer);
            scanf(" %c", &poppin);
            poppin = tolower(poppin);
            if (poppin != 'y' && poppin != 'n') {
                printf("Invalid input. Try again...\n");
            }else if(poppin == 'y'){
                printf("Which column would you like to pop?\n");
                scanf(" %d", &dropCol);
                while(dropCol > board_size-1 || dropCol < 1){
                    printf("please specify a number between 1 and %i: \n", (board_size-1));
                    scanf(" %d", &dropCol);
                }//end while
                popDiscAtColumn(board_size, board_size, board, dropCol, currentPlayer);
                if(currentPlayer == 1){
                    currentPlayer = 2;
                }else{
                    currentPlayer =1;
                }
                turn++;
                printBoard(board_size, board_size, board);
            } else{
                printf("Player %i which column would you like to drop?\n" , currentPlayer);
                scanf(" %d", &dropCol);
                printf("debug statement 1\n");
                while(dropCol > board_size-1 || dropCol < 1){
                    printf("please specify a number between 1 and %i: \n", (board_size-1));
                    scanf(" %d", &dropCol);
                }//end while
                dropDiscAtColumn(board_size, board_size, board, dropCol, currentPlayer);
                if(currentPlayer == 1){
                    currentPlayer = 2;
                }else{
                    currentPlayer =1;
                }
                turn++;
                printBoard(board_size, board_size, board);
            }

	    }else{
            printf("else \n");
            printf("Player %i which column would you like to drop?" , currentPlayer);
            scanf(" %d", &dropCol);
            printf("debug statement 1\n");
            while(*&dropCol > board_size-1 || *&dropCol < 1){
                printf("please specify a number between 1 and %i: \n", (board_size-1));
                scanf(" %d", &dropCol);
            }//end while
            printf("debug statement 2\n");
            dropDiscAtColumn(board_size, board_size, board, dropCol, currentPlayer);
            printBoard(board_size, board_size, board);
            nextPlayer(currentPlayer);
            turn++;

	    }


	}//close while.
}



//
// YOU ARE FREE TO ADD OTHER FUNCTIONS IN THIS FILE ONLY!!!
//
