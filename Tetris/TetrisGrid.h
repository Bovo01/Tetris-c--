#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include <iostream>
#include "Tetrimino.h"

namespace Tetris
{
  class TetrisGrid
  {
  private:
    /*Griglia di gioco che contiene i blocchi
      (il numero corrisponde al tipo di blocco determinato dall'enum TetriminoType)*/
    int *_grid;
    int _width{10};
    int _height{20};
    int _score{0};
    int _level{1};
    // Array of the next tetriminos
    int *_nextTetriminos;
    int _nextTetriminosNumber{4};
    // Object of the current tetrimino
    Tetrimino _currentTetrimino;

    // Private methods
    void initialize_matrix(void);
    void next_tetrimino(void);

  public:
    // Constructors / Destructor
    TetrisGrid();
    ~TetrisGrid();

    // Getters
    int width(void) const;
    int height(void) const;
    int get(int i, int j) const;
    Tetrimino current_tetrimino(void) const;
    // Graphics
    void draw(void) const;
    friend std::ostream &operator<<(std::ostream &os, const TetrisGrid &grid);
    // Events
    void key_pressed(int key);
  };
}

#endif // TETRIS_GRID_H