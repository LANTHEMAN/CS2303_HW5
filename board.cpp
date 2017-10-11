#include "board.h"
#include "organism.h"
#include <cstddef>
#include <iostream>


Board::Board(int size)
{
	this->size = size;

	Organism*** tb = new Organism**;
	Organism*** theBoard = tb;

	for(int i=0; i<size; i++){
		Organism** t= new Organism*;
		*tb = t;
		for(int j=0; j<size; j++){
			printf("%i    %i\n", i,j);
			Organism* t2 = 0;
			*t = t2;
			t++;
		}
		tb++;
	}

	// for (int i=0;i<size;i++)
	// {
	// 	printf("%i\n", i);
	// 	theBoard[i] = new Organism*;
	// }
	//
	// for(int i=0; i<size; i++){
	// 	for(int j=0; j<size; j++){
	// 		printf("%i    %i\n", i,j);
	// 		Organism* o = 0;
	// 		theBoard[i][j] = o;
	// 	}
	// }
	printf("test\n");
	this->boardRange = theBoard;
}

int Board::getSize(){
	return this->size;
}

void Board::addOrganism(Organism* o){
	boardRange[o->getRow()][o->getColumn()] = o;
}

Organism*** Board::getValues(){
	return this->boardRange;
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

	return NULL;
}


Board::~Board()
{

}
