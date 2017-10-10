#include "board.h"
#include "organism.h"

Board::Board(int size)
{
	organism** theBoard = new organism*[size];
if (theBoard) //if found size for the board
{
    for (int i = 0; i < size; i++)//for x amount of rows, generate each row 
    {
        theBoard[i] = new organism[size];
        if (!theBoard[i])// error message for can;'t find space for row i
        {
            //printf("memory fail\n");
        }        /* error */
    }
}
}

organism* Board::getEmptyCell(organism** board,organism A)
{
	
	if organism[A.colum][A.row]
}

Board::~Board()
{

}