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

void Organism::move()
{

}

void Ant::move(Board b)
{
	int rand = 0;
	bool moved = 0;

	while(!moved){
		switch(rand){
			case 0:
			if(b.isEmpty(this->row+1, this->column)){
				Organism* o = this;
				b.addToCell(o, this->row+1, this->column);
				b.clearCell(this->row, this->column);
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

void DoodleBug::move()
{

}

Organism::~Organism(){}
Ant::~Ant(){}
DoodleBug::~DoodleBug(){}
