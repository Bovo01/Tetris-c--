#include "./Tetris/TetrisGrid.h"
#include "./Tetris/Tetrimino.h"
#include "./Tetris/TetrisDrawer.cpp"
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
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
TetrisGrid grid;

int main()
{
  thread _go_down{go_down};

  while (!grid.is_game_over())
  {
    grid.key_pressed(_getch());
    draw(grid, hConsole);
  }

  return 0;
}

// Functions
void go_down(void)
{
  while (!grid.is_game_over())
  {
    Sleep(grid.speed());
    grid.move_down();
    draw(grid, hConsole);
  }
}