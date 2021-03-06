#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

extern Piece please;

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    //return  turn=(Piece)((Piece)O|(Piece)O);
    return O;
    
 }else 
    return X;
   // return Piece(turn=O);
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > BOARDSIZE)
    return Invalid;
  else if (column > BOARDSIZE)
    return Invalid;
  else {
    if(board[row][column] == Blank) {
      board[row][column] = turn;
      toggleTurn();
    } else 
      return Invalid;
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > BOARDSIZE)
    return Invalid;
  else if (column > BOARDSIZE)
    return Invalid;
  else {
    if(board[row][column] == Blank)
      return Blank;
    else
      return turn;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  static int i=0;
  Piece plays[BOARDSIZE][BOARDSIZE];
  for(int i=0; i<BOARDSIZE; i++) {
    for(int j=0; j<BOARDSIZE; j++) {
      plays[i][j] = getPiece(i,j);
      
    }
  }
 
  for(int i=0; i<BOARDSIZE; i++) {
    for(int j=0; j<BOARDSIZE; j++) {
      if(plays[i][j]==turn && plays[i][j+1]==turn && plays[i][j+2]) return turn;
      else if(plays[i][j]==turn && plays[i+1][j]==turn && plays[i+2][j]) return turn;
      else if(plays[i][j]==turn && plays[i+1][j+1]==turn && plays[i+2][j+2]) return turn;
      else if(plays[i][j]==turn && plays[i-1][j+1]==turn && plays[i-2][j+2]) return turn;
    }
  }
  return Invalid;
}
