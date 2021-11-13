#include "Tetrimino.h"

namespace Tetris
{
  class TetrisGrid
  {
  private:
    /*Griglia di gioco che contiene i blocchi
      (il numero corrisponde al tipo di blocco determinato dall'enum TetriminoType)*/
    int _grid[10][20];
    int _score;
    int _level;
    // Array of the next tetriminos
    TetriminoType *_nextTetriminos;
    int _nextTetriminosNumber;

  public:
    TetrisGrid();
    ~TetrisGrid();

    void show(void) const;
  };
}