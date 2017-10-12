#include "organism.h"
#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
	Board(int size);
	void getEmptyCell(Organism A);
	int getSize();
	Organism*** getValues();
	~Board();
	void addOrganism(Organism* o);
	void step();
	int isEmpty(int r, int c);
	void addToCell(Organism* o, int r, int c);
	void clearCell(int r, int c);
	void endStep();

private:
	int size;
	Organism*** boardRange;
};


#endif
