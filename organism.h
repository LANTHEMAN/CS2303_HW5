

#ifndef ORGANISM_H
#define ORGANISM_H
#include "board.h"

class Organism
{
public:
Organism(int r, int c);
	virtual void move(Board b);
	~Organism();
	int getRow();
	int getColumn();
	virtual int isAnt();

private:
	int survived;
	int row;
	int column;
};

class Ant: public Organism
{
public:
	Ant(int r, int c);
	void move(Board b);
	~Ant();
	int isAnt();

};

class DoodleBug: public Organism
{
public:
	DoodleBug(int r, int c);
	void move(Board b);
	~DoodleBug();
	int isAnt();

private:
	int starvation;

};

#endif
