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
    TetriminoType *_grid;
    int _width{10};
    int _height{20};
    int _score{0};
    int _level{1};
    // Array of the next tetriminos
    int *_nextTetriminos;
    int _nextTetriminosNumber{4};
    // Object of the current tetrimino
    Tetrimino _currentTetrimino;

    bool _is_game_over{false};
    bool _is_possible_back_to_back{false};

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
    TetriminoType &get(int i, int j) const;
    Tetrimino current_tetrimino(void) const;
    // Methods
    int speed(void) const;
    bool is_game_over(void) const;

    // Tetrimino modification
    void move_right(void);
    void move_left(void);
    void move_down(void);
    void rotate(void);
    void rotate_counter(void);
    // Lines deletion
    int delete_lines(void);
    // End of game
    void game_over(void);
    // Graphics
    void draw(void) const;
    friend std::ostream &operator<<(std::ostream &os, const TetrisGrid &grid);
    // Events
    void key_pressed(int key);
  };
}

#endif // TETRIS_GRID_H