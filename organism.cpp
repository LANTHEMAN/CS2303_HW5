#include "organism.h"
#include <iostream>

Organism::Organism(int r, int c)
{
	row = r;
	column = c;
	survived = 0;
}

int Organism::isAnt(){
	return 0;
}

int Ant::isAnt(){
	return 1;
}

int DoodleBug::isAnt(){
	return 0;
}

Ant::Ant(int r, int c) : Organism(r,c)
{
}

DoodleBug::DoodleBug(int r, int c) : Organism(r,c)
{

}

int Organism::getRow(){
	return this->row;
}

int Organism::getColumn(){
	return this->column;
}

void Organism::move(Organism*** boardRange, int size)
{
	printf("organism\n");
}

void Ant::move(Organism*** boardRange, int size)
{
	int random = rand() % 4;
	bool moved = false;

	int count = 0;

	while(!moved){
		switch(random){
			case 0://up
			if(this->getRow()+1 <size && boardRange[this->getRow()+1][this->getColumn()] == 0){
				Organism* o = this;
				boardRange[this->getRow()+1][this->getColumn()] = o;
				boardRange[this->getRow()][this->getColumn()] = 0;
				moved = true;

			}
			break;
			case 1://right
			if(this->getColumn()+1 <size && boardRange[this->getRow()][this->getColumn()+1] == 0){
				Organism* o = this;
				boardRange[this->getRow()][this->getColumn()+1] = o;
				boardRange[this->getRow()][this->getColumn()] = 0;
				moved = true;

			}
			break;
			case 2://down
			if(this->getRow()-1 >0 && boardRange[this->getRow()-1][this->getColumn()] == 0){
				Organism* o = this;
				boardRange[this->getRow()-1][this->getColumn()] = o;
				boardRange[this->getRow()][this->getColumn()] = 0;
				moved = true;

			}
			break;
			case 3://left
			if(this->getColumn()-1>0 && boardRange[this->getRow()][this->getColumn()-1] == 0){
				Organism* o = this;
				boardRange[this->getRow()][this->getColumn()-1] = o;
				boardRange[this->getRow()][this->getColumn()] = 0;
				moved = true;

			}
			break;
		}
		if(!moved){
		  random = (random+1)%4;
	  }

		if(count==3){
			//printf("No moves\n");
			break;
		}
		count++;
	}


}

void DoodleBug::move(Organism*** boardRange, int size)
{

}

Organism::~Organism(){}
Ant::~Ant(){}
DoodleBug::~DoodleBug(){}
