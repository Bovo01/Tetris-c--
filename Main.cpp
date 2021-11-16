#include "./Tetris/TetrisGrid.h"
#include "./Tetris/Tetrimino.h"
#include <iostream>
#include <Windows.h>
using namespace Tetris;
using namespace std;

int main()
{
  TetrisGrid grid;

  while (true)
  {
    system("cls");
    grid.draw();
    break;
  }

  return 0;
}