/***********************************************************************
Filename: othello.h

Author: Aaron Trudeau (Except for code provided)
***********************************************************************/

#ifndef OTHELLO_H_

#define OTHELLO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 8		// board size

#define BLACK 'B'	// black disc

#define WHITE 'W'	// white disc

#define EMPTY '-'	// empty spot

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE]);

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE]);

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc);

// Places the disc at location row,col and flips the opponent discs as needed 
void placeDiscAt(char board[][SIZE], int row, int col, char disc);

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc);

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE]);

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE]);

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE]);

/***********************************************************************
* Helper function prototypes
***********************************************************************/

//General helper function that returns the opponent's disc color.
char opponentDisc(char disc);

//Helper function for isValidMove that tests if a desired move can flip
//opponent pieces to the passed direction. This function supports diagonal
//moves by marking both a horizontal and a vertical direction as true.
bool isValidInDirection(char board[][SIZE], int row, int col, char disc, 
    bool right, bool left, bool up, bool down);

//A collection of isValidMove helper functions to aid readability. Tests
//for valid moves in every direction.
bool isValidRight(char board[][SIZE], int row, int col, char disc);
bool isValidLeft(char board[][SIZE], int row, int col, char disc);
bool isValidUp(char board[][SIZE], int row, int col, char disc);
bool isValidDown(char board[][SIZE], int row, int col, char disc);
bool isValidUpRight(char board[][SIZE], int row, int col, char disc);
bool isValidUpLeft(char board[][SIZE], int row, int col, char disc);
bool isValidDownRight(char board[][SIZE], int row, int col, char disc);
bool isValidDownLeft(char board[][SIZE], int row, int col, char disc);

#endif /* OTHELLO_H_ */
