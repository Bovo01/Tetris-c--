#include "./Tetris/TetrisGrid.h"
#include "./Tetris/Tetrimino.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
using namespace Tetris;
using namespace std;

// Firme di funzioni
void draw(void);
void go_down(void);

// Global variables
TetrisGrid grid;

int main()
{
  thread _go_down{go_down};

  while (!grid.is_game_over())
  {
    grid.key_pressed(_getch());
    draw();
  }

  return 0;
}

// Functions
void draw(void)
{
  system("cls");
  grid.draw();
}

void go_down(void)
{
  while (!grid.is_game_over())
  {
    Sleep(grid.speed());
    grid.move_down();
    draw();
  }
}