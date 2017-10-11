#ifndef BOARD_H
#define BOARD_H
#include "organism.h"

class Board
{
public:
	Board(int size);
	Organism* getEmptyCell(Organism A);
	int getSize();
	~Board();

private:
	int size;
	Organism*** boardRange;
};


#endif
