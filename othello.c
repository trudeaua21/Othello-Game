/***********************************************************************
Filename: othello.c

Contains funcitons to modify an othello board and determine key game
states, such as valid moves and ending conditions.

Author: Aaron Trudeau (Except for code provided)
***********************************************************************/

#include "othello.h"

//Helper function prototypes
char opponentDisc(char disc);
bool isValidRight(char board[][SIZE], int row, int col, char disc);
bool isValidLeft(char board[][SIZE], int row, int col, char disc);
bool isValidUp(char board[][SIZE], int row, int col, char disc);
bool isValidDown(char board[][SIZE], int row, int col, char disc);
bool isValidUpRight(char board[][SIZE], int row, int col, char disc);
bool isValidUpLeft(char board[][SIZE], int row, int col, char disc);
bool isValidDownRight(char board[][SIZE], int row, int col, char disc);
bool isValidDownLeft(char board[][SIZE], int row, int col, char disc);


/***********************************************************************
Displays the board (as SIZE x SIZE grid) on console.
@param board a SIZExSIZE 2D character array representing the game board
***********************************************************************/
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


/***********************************************************************
Initializes the board with start configuration of discs 
(see project specs).
@param board a SIZExSIZE 2D character array representing the game board
***********************************************************************/
void initializeBoard(char board[][SIZE])
{
    //Creates the empty board
	for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = EMPTY;
        }
    }
    
    //Adds the initial pieces to the empty board
    board[3][3] = BLACK;
    board[4][4] = BLACK;
    board[3][4] = WHITE;
    board[4][3] = WHITE;
}


/***********************************************************************
Returns true if moving the disc to location row,col is valid; else 
returns false.
@param board a SIZExSIZE 2D character array representing the game board
@param row the row value of the location of the desired move
@param col the column value of the location of the desired move
@param disc the disc value (BLACK, WHITE, or EMPTY) of the desired move
@return true if the move can result in flipped opponent pieces and 
false otherwise
***********************************************************************/
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
    // If the board space is already occupied, the move is invalid
    if(board[row][col] != EMPTY){
        return false;
    }
    
	// If there is a valid move in any direction, the move is valid
    if(isValidRight(board, row, col, disc))
        return true;
    else if(isValidLeft(board, row, col, disc))
        return true;
    else if(isValidUp(board, row, col, disc))
        return true;
    else if(isValidDown(board, row, col, disc))
        return true;
    else if(isValidDownRight(board, row, col, disc))
        return true;
    else if(isValidDownLeft(board, row, col, disc))
        return true;
    else if(isValidUpRight(board, row, col, disc))
        return true;
    else if(isValidUpLeft(board, row, col, disc))
        return true;
    else
        return false;
}

 
/***********************************************************************
Places the disc at location row,col and flips the opponent discs as 
needed.
@param board a SIZExSIZE 2D character array representing the game board
@param row the row value of the location of the desired move
@param col the column value of the location of the desired move
@param disc the disc value (BLACK, WHITE, or EMPTY) of the desired move
***********************************************************************/
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
    // Places the disc at the given location
    board[row][col] = disc;
    
    // Helper variables for manipulating pieces without changing the 
    // given values
    int changeRow = row, changeCol = col;
    
	// If there is a valid move in a direction, make that move.
    if(isValidRight(board, row, col, disc)){
        changeCol++;
        while(board[row][changeCol] != disc){
            board[row][changeCol] = disc;
            changeCol++;
        }
        // Must reset working value in case of multiple valid moves
        changeCol = col;
    }
    
    if(isValidLeft(board, row, col, disc)){
        changeCol--;
        while(board[row][changeCol] != disc){
            board[row][changeCol] = disc;
            changeCol--;
        }
        changeCol = col;
    }
    
    if(isValidUp(board, row, col, disc)){
        changeRow--;
        while(board[changeRow][col] != disc){
            board[changeRow][col] = disc;
            changeRow--;
        }
        changeRow = row;
    }
    
    if(isValidDown(board, row, col, disc)){
        changeRow++;
        while(board[changeRow][col] != disc){
            board[changeRow][col] = disc;
            changeRow++;
        }
        changeRow = row;
    }
    
    if(isValidDownRight(board, row, col, disc)){
        changeRow++;
        changeCol++;
        while(board[changeRow][changeCol] != disc){
            board[changeRow][changeCol] = disc;
            changeRow++;
            changeCol++;
        }
        changeRow = row;
        changeCol = col;
    }
    
    if(isValidDownLeft(board, row, col, disc)){
        changeRow++;
        changeCol--;
        while(board[changeRow][changeCol] != disc){
            board[changeRow][changeCol] = disc;
            changeRow++;
            changeCol--;
        }
        changeRow = row;
        changeCol = col;
    }
    
    if(isValidUpRight(board, row, col, disc)){
        changeRow--;
        changeCol++;
        while(board[changeRow][changeCol] != disc){
            board[changeRow][changeCol] = disc;
            changeRow--;
            changeCol++;
        }
        changeRow = row;
        changeCol = col;
    }
    
    if(isValidUpLeft(board, row, col, disc)){
        changeRow--;
        changeCol--;
        while(board[changeRow][changeCol] != disc){
            board[changeRow][changeCol] = disc;
            changeRow--;
            changeCol--;
        }
        changeRow = row;
        changeCol = col;
    }
}


/***********************************************************************
Returns true if a valid move for disc is available; else returns false.
@param board a SIZExSIZE 2D character array representing the game board
@param disc a non-EMPTY disc value for a prospective move
@return true if there is a possible valid move for a disc of the passed
color, and false otherwise
***********************************************************************/
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
    //Checking every board space
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            //If the board space is empty, check if move there is valid
            if(board[i][j] == EMPTY){
                //if the move is valid, then it is available
                if(isValidMove(board, i, j, disc)){
                    return true;
                }
            }
        }
    }
    //If the loop found no valid moves, then the current player
    //has no valid moves avaialable
	return false;
}

 
/***********************************************************************
Returns true if the board is fully occupied with discs; else returns 
false.
@param board a SIZExSIZE 2D character array representing the game board
@return true if there are no EMPTY spaces left on the board, and false
otherwise
***********************************************************************/
bool isBoardFull(char board[][SIZE])
{
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            //If there is an empty space, the board is not full
            if(board[i][j] == EMPTY){
                return false;
            }
        }
    }
    //If the function has not returned false, it hasn't encounterd any 
    //empty spaces and the board is full
    return true;
}


/***********************************************************************
Returns true if either the board is full or a valid move is not 
available for either disc.
@param board a SIZExSIZE 2D character array representing the game board
@return true if the game cannot continue, and false if there are valid
moves left
***********************************************************************/
bool isGameOver(char board[][SIZE])
{
    if(isBoardFull(board) || (!isValidMoveAvailable(board, BLACK) && 
        !isValidMoveAvailable(board, WHITE))){
        return true;
    }
    else{
        return false;
    }
}


/***********************************************************************
If there is a winner, it returns the disc (BLACK or WHITE) associated 
with the winner. In case of a tie, it returns EMPTY
@param board a SIZExSIZE 2D character array representing the game board
@return the disc value associated with the winner, and EMPTY in case of
a tie
***********************************************************************/
char checkWinner(char board[][SIZE])
{
    //Declare variables to count the discs of each player
    int bCount = 0, wCount = 0;
    
    //Counts how many discs of each color there are
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == BLACK){
                bCount++;
            }
            else if(board[i][j] == WHITE){
                wCount++;
            }
        }
    }
    
    //The winner is whichever player has more discs on the board
    //Return EMPTY if the game is a tie
    if(bCount > wCount){
        return BLACK;
    }
    else if(bCount < wCount){
        return WHITE;
    }
    else{
        return EMPTY;
    }
}

////////////////////////////////////////////////////////////////////////
//My own helper functions
////////////////////////////////////////////////////////////////////////

/***********************************************************************
General helper function that returns the opponent's disc color.
@param disc a disc value (BLACK, WHITE, or EMPTY).
@return BLACK if the passed disc is WHITE, and WHITE if the passed disc
is BLACK
***********************************************************************/
char opponentDisc(char disc){
    if(disc == BLACK){
        return WHITE;
    }
    else{
        return BLACK;
    }
}


/***********************************************************************
Helper function for isValidMove that tests if a desired move can flip
opponent pieces to the passed direction. This function supports diagonal
moves by marking both a horizontal and a vertical direction as true.
@param board a SIZExSIZE 2D character array representing the game board
@param row the row value of the location of the desired move
@param col the column value of the location of the desired move
@param disc the disc value (BLACK, WHITE, or EMPTY) of the desired move
@param right indicates whether to check for a move to the right
@param left indicates whether to check for a move to the left
@param up indicates whether to check for a move upwards
@param down indicates whether to check for a move downwards
@return true if the move can result in flipped opponent pieces to the
indicated direction, and false otherwise
***********************************************************************/
bool isValidInDirection(char board[][SIZE], int row, int col, char disc, 
    bool right, bool left, bool up, bool down){
    
    // Prevents condradicting input conditions
    if(!right && !left && !up && !down)
        return false;
    
    int testCol = col, testRow = row;
    int rowIncrement = 0, colIncrement = 0;
    char oppDisc = opponentDisc(disc);
    
    
    if(right){
        if(col > (SIZE - 3))
            return false;
        colIncrement = 1;
    }
    else if(left){
        if(col < 2)
            return false;
        colIncrement = -1;
    }
    
    if(up){
        if (row < 2)
            return false;
        rowIncrement = -1;
    }

    else if(down){
        if(row > (SIZE - 3))
            return false;
        rowIncrement = 1;
    }
    
    testRow += rowIncrement;
    testCol += colIncrement;
    
    if(board[testRow][testCol] != oppDisc)
        return false;
    
    testRow += rowIncrement;
    testCol += colIncrement;
    
    while(testRow >= 0 && testRow < SIZE && testCol >=0 && testCol < SIZE){
        
        //If we encounter an allied disc, the move is valid
        if(board[testRow][testCol] == disc){
            return true;
        }
        
        //If we encounter an empty space, the move is invalid
        else if(board[testRow][testCol] == EMPTY){
            return false;
        }
        
        testRow += rowIncrement;
        testCol += colIncrement;
    }
    
    return false;
    
}


/***********************************************************************
A collection of isValidMove helper functions to aid readability. Tests
for valid moves in every direction.
@param board a SIZExSIZE 2D character array representing the game board
@param row the row value of the location of the desired move
@param col the column value of the location of the desired move
@param disc the disc value (BLACK, WHITE, or EMPTY) of the desired move
@return true if the move can result in flipped opponent pieces to the
desired direction, and false otherwise
***********************************************************************/
bool isValidRight(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              true, false, false, false);
}
bool isValidLeft(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              false, true, false, false);
}
bool isValidUp(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              false, false, true, false);
}
bool isValidDown(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              false, false, false, true);
}
bool isValidUpRight(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              true, false, true, false);
}
bool isValidUpLeft(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              false, true, true, false);
}
bool isValidDownRight(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              true, false, false, true);
}
bool isValidDownLeft(char board[][SIZE], int row, int col, char disc){
    return isValidInDirection(board, row, col, disc, 
                              false, true, false, true);
}
