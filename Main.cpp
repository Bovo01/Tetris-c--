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
void go_down(void);
void input_manager(void);

// Global variables
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
TetrisGrid grid;
unsigned short int fps = 75;

int main()
{
  thread _go_down{go_down};
  thread _input_manager{input_manager};

  while (!grid.is_game_over())
  {
    Sleep(1000 / fps);
    Tetris::draw(grid, hConsole);
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
  }
}
// Gestisce gli input da tastiera
void input_manager(void)
{
  while (!grid.is_game_over())
  {
    grid.key_pressed(_getch());
  }
}