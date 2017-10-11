#include "organism.h"

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

}

void Ant::move(Organism*** boardRange, int size)
{
	int rand = 0;
	bool moved = 0;

	while(!moved){
		switch(rand){
			case 0:
			if(this->getRow()+1 <size && boardRange[this->getRow()+1][this->getColumn()]){
				Organism* o = this;
				boardRange[this->getRow()+1][this->getColumn()] = o;
				moved = 1;

			}
			break;
			case 1:
			break;
			case 2:
			break;
			case 3:
			break;
		}
		rand = (rand+1)%4;
	}


}

void DoodleBug::move(Organism*** boardRange, int size)
{

}

Organism::~Organism(){}
Ant::~Ant(){}
DoodleBug::~DoodleBug(){}
