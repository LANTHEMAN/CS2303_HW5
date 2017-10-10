//Author: LMAO RWITTENBURG
#include <cstdlib>
#include <iostream>
#include "board.h"
/*PA5 gridSize #doodlebugs #ants #time_steps seed pause*/
int main(int argc, char* argv[])
{
    int gridSize;
    int numBug;
    int numAnt;
    int steps;
    int seed;
    int pause;
  switch(argc)
  {
    case 1:
    gridSize = 20;
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 2:
    gridSize = atoi(argv[1]);
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 3:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 4:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 5:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = 1;
    pause = 0;
    break;

    case 6:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = atoi(argv[6]);
    pause = 0;
    break;
    
    case 7:
    gridSize = atoi(argv[1]);//
    numBug = atoi(argv[2]);//
    numAnt = atoi(argv[3]);//
    steps = atoi(argv[4]);//
    seed = atoi(argv[5]);
    pause = atoi(argv[6]);
    break;
  }

    Board newboard(gridSize);


}
