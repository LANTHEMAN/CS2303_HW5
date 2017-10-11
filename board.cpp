#include "board.h"
#include "organism.h"
#include <cstddef>


Board::Board(int size)
{
	this->size = size;
	Organism*** theBoard = new Organism**;
	for (int i=0;i<size;i++)
	{
		theBoard[i] = new Organism*;
		for(int j=0; j<size; j++){
			theBoard[i][j] = 0;
		}
	}
	this->boardRange = theBoard;
}

int Board::getSize(){
	return this->size;
}

Organism* Board::getEmptyCell(Organism A)
{

	//check top
	if (A.getColumn()+1 < this->getSize() && boardRange[A.getColumn()+1][A.getRow()]){
		return boardRange[A.getColumn()+1][A.getRow()];
	}

	//check right
	if (A.getRow()+1 < this->getSize() && boardRange[A.getColumn()][A.getRow()+1]){
		return boardRange[A.getColumn()][A.getRow()+1];
	}

	//check down
	if (A.getColumn()-1 >= 0 && boardRange[A.getColumn()][A.getRow()+1]){
		return boardRange[A.getColumn()-1][A.getRow()];
	}

	//check left
	if ((A.getRow()-11 >= 0) && (boardRange[A.getColumn()][A.getRow()-1])){
		return boardRange[A.getColumn()][A.getRow()-1];
	}
}


Board::~Board()
{

}
