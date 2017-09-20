/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.toggleTurn() == O);
	ASSERT_TRUE(board.toggleTurn() == X);
	ASSERT_TRUE(board.toggleTurn() != X);
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,0) == X);
	board.getPiece(0,0);
	ASSERT_TRUE(board.placePiece(0,0) == X);
	board.getPiece(0,0);
	ASSERT_TRUE(board.placePiece(0,1) == O);
	board.getPiece(0,1);
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getPiece(0,0) == Blank);
	ASSERT_TRUE(board.getPiece(BOARDSIZE * 2, BOARDSIZE * 2) == Invalid);
	ASSERT_TRUE(board.getPiece(-1, -1) == Invalid);
	board.placePiece(0,0);
	ASSERT_TRUE(board.getPiece(0,0) == X);
	board.placePiece(0,0);
	ASSERT_TRUE(board.getPiece(0,0) == X);
	board.placePiece(0,1);
	ASSERT_TRUE(board.getPiece(0,1) == O);
}

TEST(TicTacToeBoardTest, getWinnerHorizontal)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getWinner() == Invalid);
	// Fill first row.
	for (int i = 0; i < BOARDSIZE; i++) {
		board.placePiece(0, i);
		board.toggleTurn();
	}
	ASSERT_TRUE(board.getWinner() != Invalid);
	ASSERT_TRUE(board.getWinner() == X);
	ASSERT_TRUE(board.getWinner() != O);
}

TEST(TicTacToeBoardTest, getWinnerVertical)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getWinner() == Invalid);
	// Fill first column.
	for (int i = 0; i < BOARDSIZE; i++) {
		board.placePiece(i, 0);
		board.toggleTurn();
	}
	ASSERT_TRUE(board.getWinner() != Invalid);
	ASSERT_TRUE(board.getWinner() == X);
	ASSERT_TRUE(board.getWinner() != O);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalTopLeft)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getWinner() == Invalid);
	// Fill top left to bottom right diagonal.
	for (int i = 0; i < BOARDSIZE; i++) {
		board.placePiece(i, i);
		board.toggleTurn();
	}
	ASSERT_TRUE(board.getWinner() != Invalid);
	ASSERT_TRUE(board.getWinner() == X);
	ASSERT_TRUE(board.getWinner() != O);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalTopRight)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getWinner() == Invalid);
	// Fill top left to bottom right diagonal.
	for (int i = 0; i < BOARDSIZE; i++) {
		board.placePiece((BOARDSIZE - 1) - i, i);
		board.toggleTurn();
	}
	ASSERT_TRUE(board.getWinner() != Invalid);
	ASSERT_TRUE(board.getWinner() == X);
	ASSERT_TRUE(board.getWinner() != O);
}