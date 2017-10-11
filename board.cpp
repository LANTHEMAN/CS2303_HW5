#include "board.h"
#include "organism.h"



Board::Board(int size)
{
	this.size = size;
	organism** theBoard = new organism*[size];
  if (theBoard) //if found size for the board
  {
		for (int i = 0; i < size; i++)//for x amount of rows, generate each row
    {
			theBoard[i] = new organism[size];
      if (!theBoard[i])// error message for can;'t find space for row i
      {
            //printf("memory fail\n");
      }        /* error */
    }
  }
}

Board::getSize(){
	return this.size;
}

organism** Board::getEmptyCell(Board board, organism A)
{

	//check top
	if (A.getColumn()+1 < board.getSize() && board[A.getColum()+1][A.getRow()] == null){
		return board[A.getColum()+1][A.getRow()];
	}

	//check right
	if (A.getRow()+1 < board.getSize() && board[A.getColum()][A.getRow()+1] == null){
		return board[A.getColum()][A.getRow()+1];
	}

	//check down
	if (A.getColumn()-1 >= 0 && board[A.getColum()][A.getRow()+1] == null){
		return board[A.getColum()-1][A.getRow()];
	}

	//check left
	if (A.getRow()-11 >= 0 && board[A.getColum()][A.getRow()-1] == null){
		return board[A.getColum()][A.getRow()-1];
	}
}


Board::~Board()
{

}
