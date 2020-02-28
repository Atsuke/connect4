//***************************************************
// Filename: connect_game.c
//
// Author: 	YOUR NAME(S)
//			Jag Nandigam
//***************************************************

#include <stdio.h>
#include "connect_game.h"

// Initializes the board to 0s (use the macro EMPTY in the code)
void initializeBoard(int nrows, int ncols, int board[][ncols])
{
	for(int i =0; i < nrows; i++){
	    for(int j = 0; j < ncols; j ++){
	        board[i][j] = 0;
	    }//close for

	}//close for
}

// Drops the disc in column indicated by dropCol and returns true.
// Returns false if dropping the disc in dropCol is not valid.
bool dropDiscAtColumn(int nrows, int ncols, int board[][ncols], int dropCol, int player)
{
bool droppable = false;
    //Start at the bottom and work up until we find an empty spot.
	for(int i = nrows; i >0; i--){
	    if(board[i][dropCol-1] == 0){
            board[i][dropCol-1] = player;
            droppable = true;
            break;
	    } else{
            droppable = false;
	    }
	}
    return droppable;
}

// Pops the player's disc from bottom in column indicated by popCol and returns true.
// Returns false if popping the disc in popCol is not valid.
bool popDiscAtColumn(int nrows, int ncols, int board[][ncols], int popCol, int player)
{
    bool poppable = false;
    if(board[nrows-1][popCol-1] != 0){
        for(int i = nrows-1; i > 0; i--){
            board[i][popCol-1] = board[i-1][popCol-1];
        }
        board[0][popCol-1] = 0;
    }else{

        return poppable;
    }

}

// Returns true if the board is full, false otherwise.
bool isBoardFull(int nrows, int ncols, int board[][ncols])
{
    bool full = true;
    for(int i =0; i < nrows; i++){
        for(int j = 0; j < ncols; j ++){
            if(board[i][j] == 0){
                full = false;
            }
        }//close for

    }//close for

	return full;
}

// Prints the board to standard output in a grid format with columns labelled.
void printBoard(int nrows, int ncols, int board[][ncols])
{
    printf("\n");
    for(int a = 1; a < ncols; a++){// print the numbers at the top of the columns
        printf("| %i ", a);
    }
    if(ncols < 10){//Spacing gets weird due to the extra digit in 10.
        printf("| %i |", ncols);
    } else{//adjust for 10
        printf("| %i|", ncols);
    }

    printf("\n"); //new line to start printing the "blank squares"

    //nested for loop to initialize the board to all 0's
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j ++){
            printf("| %i ",board[i][j]);
            }//close for
        printf("|\n");
    }//close for
}

// Return true if the player has achieved the required match of discs of
// specified length horizontally, vertically, or diagonally, false otherwise.
bool isWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player)
{
	return isHorizontalWinByPlayer(nrows, ncols, board, connect_length, player) ||
		   isVerticalWinByPlayer(nrows, ncols, board, connect_length, player) ||
		   isDiagonalWinByPlayer(nrows, ncols, board, connect_length, player);
}

// Return true if the player has achieved the required match of discs of
// specified length horizontally, false otherwise.
bool isHorizontalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player)
{
    //nested for loop that starts at row 1 and increments column by column checking for the win
    bool win = false;
    int counter = 0;
    for(int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if(board[i][j] == player){
                counter++;
                if(counter == connect_length){
                    win = true;
                }
            }else{
                counter = 0;
            }

        }
    }
	return win;
}

// Return true if the player has achieved the required match of discs of
// specified length vertically, false otherwise.
bool isVerticalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player)
{
    //nested for loop that starts at column 1 and increments row by row checking for the win
    bool win = false;
    int counter = 0;
    for(int j = 0; j < ncols; j++) {
        for (int i = 0; i < nrows; i++) {
            if(board[i][j] == player){
                counter++;
                if(counter == connect_length){
                    win = true;
                }
            }else{
                counter = 0;
            }

        }
    }
    return win;
}

// Return true if the player has achieved the required match of discs of
// specified length diagonally, false otherwise.
bool isDiagonalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player)
{
    int counter = 0;
    int offset = 0;
    bool win = false;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            //down right case
            while((counter < connect_length) && (j + offset < ncols) &&  (board[i + offset][j + offset] == player)){
                    counter++;
                    offset++;
                    if(counter == connect_length){
                        win = true;
                        break;
                    }//close if
            }//close while
            counter = 0;
            //up right case
            while((counter < connect_length) && (i - offset >= 0) && (j + offset < ncols) &&  (board[i - offset][j + offset] == player)){
                counter++;
                offset++;
                if(counter == connect_length){
                    win = true;
                    break;
                }
            }//close while
        }//close inner for
    }//close outer for

	return win;
}//close isDiagonalWinByPlayer
