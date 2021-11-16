#include "./Tetris/TetrisGrid.h"
#include "./Tetris/Tetrimino.h"
#include <iostream>
#include <Windows.h>
#include <thread>
using namespace Tetris;
using namespace std;

// Firme di funzioni
void draw(void);
void go_down(void);

// Variabili globali
TetrisGrid grid;

int main()
{
  thread _go_down{go_down};

  while (!grid.is_game_over())
  {
    //system("cls");
    //grid.draw();
    //break;
  }

  return 0;
}

void draw(void)
{
  system("cls");
  grid.draw();
}

void go_down(void)
{
  while (!grid.is_game_over())
  {
    Sleep(1000);
    grid.move_down();
    draw();
  }
}