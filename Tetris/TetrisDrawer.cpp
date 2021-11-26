#include <windows.h>
#include <iostream>
#include "TetrisGrid.h"

namespace Tetris
{
  constexpr int DEFAULT_BACKGROUND_COLOR = 0x0F;
  void draw(const TetrisGrid &grid, const HANDLE &hConsole)
  {
    system("cls");
    std::cout << "\n\tScore: " << grid.score() << std::endl;
    std::cout << "\tLevel: " << grid.level() << std::endl << std::endl;
    Tetrimino next;
    // Disegno il gioco (con una cornice e i blocchi successivi)
    for (int y = 0; y < grid.height() + 2; y++)
    {
      for (int x = 0; x < grid.width() + 2 + 6; x++)
      {
        // Cornice che chiude il gioco
        if (((y == 0 || y == grid.height() + 1) && x < grid.width() + 1) ||
            (x == 0 || x == grid.width() + 1))
        {
          std::cout << '#';
          continue;
        }
        // Se sono dentro il gioco disegno i blocchi
        if (x >= 1 && x <= grid.width() && y >= 1 && y <= grid.height())
        {
          if (grid.current_tetrimino().is_occupied(x - 1, y - 1))
            SetConsoleTextAttribute(hConsole, Tetris::get_color_from_tetrimino(grid.current_tetrimino().type()));
          else if (grid.get(x - 1, y - 1) != NONE)
            SetConsoleTextAttribute(hConsole, Tetris::get_color_from_tetrimino(grid.get(x - 1, y - 1)));
          std::cout << ' ';
        }
        // Se sono oltre il gioco disegno i prossimi tetramini
        if (x > grid.width() + 1 && ((double)y / 4) <= grid.next_tetriminos_number())
        {
          if (x == grid.width() + 2 + 6 - 1) {
            std::cout << '#';
            continue;
          }
          if (y % 4 == 0)
          {
            std::cout << '#';
            if (x == grid.width() + 3)
            {
              next = {
                  grid.get_next_tetrimino((short)(y / 4)),
                  (short)(x + 2), (short)(y + 2)};
            }
            continue;
          }
          if (next.is_occupied(x, y))
            SetConsoleTextAttribute(hConsole, Tetris::get_color_from_tetrimino(next.type()));
          std::cout << ' ';
        }
        SetConsoleTextAttribute(hConsole, DEFAULT_BACKGROUND_COLOR);
      }
      std::cout << std::endl;
    }
  }
}