#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;

/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i = 0; i < BOARDSIZE; i++) {
    for(int j = 0; j < BOARDSIZE; j++) {
      board[i][j] = Blank;
    }
  }
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X) {
    turn = O;
  } else {
    turn = X;
  }
  return turn;
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
  if (getPiece(row, column) == Invalid || getWinner() != Invalid) return Invalid;
  if (getPiece(row, column) == Blank) {
    board[row][column] = turn;
    toggleTurn();
  } else {
    return Invalid;
  }
  return getPiece(row, column);
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  // If position is out of board bounds, then return Invalid.
  if (row >= BOARDSIZE || row < 0 || column >= BOARDSIZE || column < 0) return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece winner = Invalid;

  // Check for horizontal wins.
  bool isRowSame = false;
  for (int i = 0; i < BOARDSIZE; i++) {
    for (int j = 0; j < BOARDSIZE - 1; j++) {
      // Check if first two pieces match.
      if (j == 0) {
        isRowSame = getPiece(i, j) == getPiece(i, j + 1);
        if (getPiece(i, j) == Blank) isRowSame = false;
      }
      // Check if current two pieces and previous pieces match.
      else isRowSame = getPiece(i, j) == getPiece(i, j + 1) && isRowSame;
    }
    if (isRowSame) {
      winner = getPiece(i, 0);
    }
  }

  // Check for vertical wins.
  bool isColumnSame = false;
  for (int j = 0; j < BOARDSIZE; j++) {
    for (int i = 0; i < BOARDSIZE - 1; i++) {
      // Check if first two pieces match.
      if (i == 0) {
        isColumnSame = getPiece(i, j) == getPiece(i + 1, j);
        if (getPiece(i, j) == Blank) isColumnSame = false;
      }
      // Check if current two pieces and previous pieces match.
      else isColumnSame = getPiece(i, j) == getPiece(i + 1, j) && isColumnSame;
    }
    if (isColumnSame) {
      winner = getPiece(0, j);
    }
  }

  // Check for diagonal top left to bottom right win.
  bool isDiagonalSame = false;
  for (int i = 0; i < BOARDSIZE - 1; i++) {
    // Check if first two pieces match.
    if (i == 0) {
      isDiagonalSame = getPiece(i, i) == getPiece(i + 1, i + 1);
      if (getPiece(i, i) == Blank) isDiagonalSame = false;
    }
    // Check if current two pieces and previous pieces match.
    else isDiagonalSame = getPiece(i, i) == getPiece(i + 1, i + 1) && isDiagonalSame;
  }
  if (isDiagonalSame) {
    winner = getPiece(0, 0);
  }

  // Check for diagonal top right to bottom left win.
  isDiagonalSame = false;
  for (int i = 0; i < BOARDSIZE - 1; i++) {
    // Check if first two pieces match.
    if (i == 0) {
      isDiagonalSame = getPiece((BOARDSIZE - 1) - i, i) == getPiece((BOARDSIZE - 1) - i - 1, i + 1);
      if (getPiece((BOARDSIZE - 1) - i, i) == Blank) isDiagonalSame = false;
    }
    // Check if current two pieces and previous pieces match.
    else isDiagonalSame = getPiece((BOARDSIZE - 1) - i, i) == getPiece((BOARDSIZE - 1) - i - 1, i + 1) && isDiagonalSame;
  }
  if (isDiagonalSame) {
    winner = getPiece(0, BOARDSIZE - 1);
  }

  // If there is no winner, check board to see if there is a tie.
  if (winner == Invalid) {
    bool isTie = true;
    for (int i = 0; i < BOARDSIZE; i++) {
      for (int j = 0; j < BOARDSIZE; j++) {
        if (getPiece(i, j) == Blank) isTie = false;
      }
    }
    if (isTie) return Blank;
  }

  return winner;
}
