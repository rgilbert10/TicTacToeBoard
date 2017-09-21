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

//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


TEST(TicTacToeBoardTest, shouldWork) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(1,0);
	board.placePiece(0,2);
	Piece p =board.getWinner();
	ASSERT_EQ(X, p);
}