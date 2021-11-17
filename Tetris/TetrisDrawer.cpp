#include <windows.h>
#include <iostream>
#include "TetrisGrid.h"

namespace Tetris
{
  constexpr int DEFAULT_COLOR_BACKGROUND = 15;
  void draw(const TetrisGrid &grid, const HANDLE &hConsole)
  {
    system("cls");
    // Disegno il gioco (con una cornice) per righe
    for (int i = 0; i < grid.height() + 2; i++)
    {
      for (int j = 0; j < grid.width() + 2; j++)
      {
        // Cornice sopra e sotto
        if ((i == 0 || i == grid.height() + 1) ||
            (j == 0 || j == grid.width() + 1))
        {
          std::cout << '#';
          continue;
        }
        // TODO output blocco in base al tipo salvato in _grid
        if (grid.current_tetrimino().is_occupied(j - 1, i - 1))
          SetConsoleTextAttribute(hConsole, Tetris::get_color_from_tetrimino(grid.current_tetrimino().type()));
        else if (grid.get(j - 1, i - 1) != NONE)
          SetConsoleTextAttribute(hConsole, Tetris::get_color_from_tetrimino(grid.get(j - 1, i - 1)));
        std::cout << ' ';
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR_BACKGROUND);
      }
      std::cout << std::endl;
    }
  }
}