# Othello-Game

A basic terminal-based othello game built using C. 

## Information on Running
Run from the command line using argument structure './executableName startingPlayerNumber startingPlayerColor', where 'executableName' refers to the executable created by compiling the main.c file, 'startingPlayerNumber' refers to which player (1 or 2) starts the game and 'startingPlayerColor' refers to the color (B for Black and W for White) that player will use.

## Information on Moves
Moves are made by typing in the desired row and column to place a piece. The game catches invalid move choices and handles them accordingly, prompting the user to re-enter their move. 

## In the Works
I am currently in the works of extending this project to include online multiplayer. This will be implemented via a client/server architechture to connect two clients looking for someone to play with. 

All game logic will be run on the server, whereas the clients will handle displaying the game board, accepting user input, and trasnporting client move commands to the server. 
