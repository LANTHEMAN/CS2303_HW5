#ifndef BOARD_H
#define BOARD_H
#include "organism.h"

class Board
{
public:
	Board(int size);
	organism* getEmptyCell(organism** board);
	~Board();

private:
	int size;
};


#endif
