#include "board.h"
#include "organism.h"
#include <cstddef>
#include <iostream>


Board::Board(int size)
{
	this->size = size;

	Organism*** theBoard = new Organism**;

	for (int i=0;i<size;i++)
	{
		printf("%i\n", i);
		theBoard[i] = new Organism*;
	}

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%i    %i\n", i,j);
			Organism* o = 0;

			theBoard[i][j] = o;
		}
	}
	printf("test\n");
	this->boardRange = theBoard;
}

int Board::getSize(){
	return this->size;
}

//move doodlebug first
void Board::step(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 0){
				o->move();
			}
		}
	}

	//move ants second
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 1){
				o->move();
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
