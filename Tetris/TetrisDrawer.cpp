#include <windows.h>
#include <iostream>
#include "TetrisGrid.h"

namespace Tetris
{
  void draw(TetrisGrid &grid)
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
          std::cout << 'X';
        else
        {
          if (grid.get(i - 1, j - 1) == 0)
            std::cout << ' ';
          else
            std::cout << grid.get(i - 1, j - 1); //TODO Converti in carattere colorato
        }
      }
      std::cout << std::endl;
    }
  }
}