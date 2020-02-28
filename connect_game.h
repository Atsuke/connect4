//***************************************************
// Filename: connect_game.h
//
// Author: 	Jag Nandigam
//
// 		!!!!! DO NOT MODIFY THIS FILE !!!!!
//***************************************************

#ifndef CONNECT4_H_
#define CONNECT4_H_

#include <stdbool.h>

#define EMPTY 0

// Initializes the board to 0s (use the macro EMPTY in the code)
void initializeBoard(int nrows, int ncols, int board[][ncols]);

// Drops the disc in column indicated by dropCol and returns true.
// Returns false if dropping the disc in dropCol is not valid.
bool dropDiscAtColumn(int nrows, int ncols, int board[][ncols], int dropCol, int player);

// Pops the player's disc from bottom in column indicated by popCol and returns true.
// Returns false if popping the disc in popCol is not valid.
bool popDiscAtColumn(int nrows, int ncols, int board[][ncols], int popCol, int player);

// Returns true if the board is full, false otherwise.
bool isBoardFull(int nrows, int ncols, int board[][ncols]);

// Prints the board to standard output in a grid format with columns labelled.
void printBoard(int nrows, int ncols, int board[][ncols]);

// Return true if the player has achieved the required match of discs of
// specified length horizontally, vertically, or diagonally, false otherwise.
bool isWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player);

// Return true if the player has achieved the required match of discs of
// specified length horizontally, false otherwise.
bool isHorizontalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player);

// Return true if the player has achieved the required match of discs of
// specified length vertically, false otherwise.
bool isVerticalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player);

// Return true if the player has achieved the required match of discs of
// specified length diagonally, false otherwise.
bool isDiagonalWinByPlayer(int nrows, int ncols, int board[][ncols], int connect_length, int player);

#endif /* CONNECT4_H_ */
