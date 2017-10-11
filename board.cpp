#include "board.h"
#include "organism.h"
#include <cstddef>
#include <iostream>


Board::Board(int size)
{
	this->size = size;

	Organism*** theBoard = new Organism**[size];

	for (int i=0;i<size;i++)
	{
		theBoard[i] = new Organism*[size];
	}

	this->boardRange = theBoard;
}

int Board::getSize(){
	return this->size;
}


void Board::step(){
	//move doodlebug first

	printf("MOVING DBBBS\n");
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 0){
				o->move(boardRange, size);
			}
		}
	}

	//move ants second
	printf("MOVING ANTSSSS\n");
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];

			if(o && o->isAnt() == 1){

				o->move(boardRange, size);
			}
		}
	}
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


int Board::isEmpty(int r, int c){
	if(boardRange[r][c]){
		return 0;
	}else{
		return 1;
	}
}

void Board::addToCell(Organism* o, int r, int c){
	boardRange[r][c] = o;
}

void Board::clearCell(int r, int c){
	boardRange[r][c] = 0;
}
