#include "board.h"
#include "organism.h"
#include <cstddef>
#include <iostream>
int newRow;
int newColumn;

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
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 0){
				o->move(boardRange, size);
			}
		}
	}

	//move ants second
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];

			if(o && o->isAnt() == 1){

				o->move(boardRange, size);
			}
		}
	}
}

void Board::endStep(){

	//doodlebugs
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 0){
				if(o->getStarvation() >=3){
					boardRange[i][j] = 0;
				}
				if(o->getSurvived() >=8)
				{
					this->getEmptyCell(o);
				 DoodleBug* d = new DoodleBug(newRow,newColumn);
				 this->addOrganism(d);
				}
			}
		}
	}

	//ants second
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Organism* o = boardRange[i][j];
			if(o && o->isAnt() == 1){
				o->survive();
				if(o->getSurvived()>=3)
				{
					this->getEmptyCell(o);
					Ant* A = new Ant(newRow,newColumn);
					this->addOrganism(A);
				}

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

void Board::getEmptyCell(Organism* A)
{
	int random = rand() % 4;
	bool selected = false;
	int count = 0;
	while(!selected){
		switch(random){
			case 0://up
	//check top
	if (A->getColumn()+1 < this->getSize() && boardRange[A->getColumn()+1][A->getRow()])
	{
		newRow = A->getRow();
		newColumn = A->getColumn()+1;
		selected = true;
	}
	break;
	case 1:
	//check right
	if (A->getRow()+1 < this->getSize() && boardRange[A->getColumn()][A->getRow()+1])
	{
		newRow = A->getRow()+1;
		newColumn = A->getColumn();
		selected = true;
	}
	break;

	case 2:
	//check down
	if (A->getColumn()-1 >= 0 && boardRange[A->getColumn()][A->getRow()+1]){
		newRow = A->getRow();
		newColumn = A->getColumn()-1;
		selected = true;
	}
	break;

	case 3:
	//check left
	if ((A->getRow()-11 >= 0) && (boardRange[A->getColumn()][A->getRow()-1])){
		newRow = A->getRow()-1;
		newColumn = A->getColumn();
		selected = true;
	}
	break;
}
	if(!selected){
		random = (random+1)%4;
	}

	if(count==3){
		break;
	}
	count++;
}
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
