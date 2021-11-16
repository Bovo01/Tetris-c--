#include <math.h>
#include "Tetrimino.h"
#include "TetrisGrid.h"

#define _USE_MATH_DEFINES // Include M_PI

namespace Tetris
{
  // Constructor
  Tetrimino::Tetrimino() {}
  Tetrimino::Tetrimino(TetriminoType type, TetrisGrid *grid) : _type(type), _grid(grid)
  {
    initialize_position(type);
  }
  // Destructor
  Tetrimino::~Tetrimino() {}

  // Initialize pivot and blocks
  void Tetrimino::initialize_position(TetriminoType type)
  {
    _pivot_y = 0;
    switch (type)
    {
    case I:
      _pivot_x = ((int)_grid->width() / 2) - .5;
      _positions[0] = Position(_pivot_x - 1.5, 0);
      _positions[1] = Position(_pivot_x - .5, 0);
      _positions[2] = Position(_pivot_x + .5, 0);
      _positions[3] = Position(_pivot_x + 1.5, 0);
      break;
    case J:
      _pivot_x = ((int)_grid->width() / 2);
      _positions[0] = Position(_pivot_x - 1, 1);
      _positions[1] = Position(_pivot_x, 1);
      _positions[2] = Position(_pivot_x + 1, 1);
      _positions[3] = Position(_pivot_x + 1, 0);
      break;
    case L:
      _pivot_x = ((int)_grid->width() / 2);
      _positions[0] = Position(_pivot_x - 1, 1);
      _positions[1] = Position(_pivot_x, 1);
      _positions[2] = Position(_pivot_x + 1, 1);
      _positions[3] = Position(_pivot_x - 1, 0);
      break;
    case O:
      _pivot_x = ((int)_grid->width() / 2) - .5;
      _positions[0] = Position(_pivot_x - .5, 0);
      _positions[1] = Position(_pivot_x + .5, 0);
      _positions[2] = Position(_pivot_x - .5, 1);
      _positions[3] = Position(_pivot_x + .5, 1);
      break;
    case S:
      _pivot_x = (int)_grid->width() / 2;
      _positions[0] = Position(_pivot_x - 1, 1);
      _positions[1] = Position(_pivot_x, 1);
      _positions[2] = Position(_pivot_x, 0);
      _positions[3] = Position(_pivot_x + 1, 0);
      break;
    case Z:
      _pivot_x = (int)_grid->width() / 2;
      _positions[0] = Position(_pivot_x + 1, 1);
      _positions[1] = Position(_pivot_x, 1);
      _positions[2] = Position(_pivot_x, 0);
      _positions[3] = Position(_pivot_x - 1, 0);
      break;
    case T:
      _pivot_x = (int)_grid->width() / 2;
      _positions[0] = Position(_pivot_x + 1, 1);
      _positions[1] = Position(_pivot_x, 1);
      _positions[2] = Position(_pivot_x, 0);
      _positions[3] = Position(_pivot_x - 1, 1);
    }
  }

  // Assignment operator
  Tetrimino &Tetrimino::operator=(const Tetrimino &other)
  {
    _type = other._type;
    _grid = other._grid;
    _pivot_x = other._pivot_x;
    _pivot_y = other._pivot_y;
    for (int i = 0; i < 4; i++)
    {
      _positions[i] = other._positions[i];
    }
    return *this;
  }

  // Move the tetrimino
  void Tetrimino::move(short x_amount, short y_amount)
  {
    _pivot_x += x_amount;
    _pivot_y += y_amount;
    for (int i = 0; i < 4; i++)
    {
      _positions[i].x += x_amount;
      _positions[i].y += y_amount;
    }
  }

  // Rotate the tetrimino
  void Tetrimino::rotate(short times = 1)
  {
    double angle = (times % 4) * M_PI / 2;
    for (int i = 0; i < 4; i++)
    {
      _positions[i].x = _pivot_x + (cos(angle) * (_positions[i].x - _pivot_x) - sin(angle) * (_positions[i].y - _pivot_y));
      _positions[i].y = _pivot_y + (sin(angle) * (_positions[i].x - _pivot_x) + cos(angle) * (_positions[i].y - _pivot_y));
    }
  }

  //
  bool Tetrimino::is_occupied(short x, short y)
  {
    for (int i = 0; i < 4; i++)
    {
      if (_positions[i].x == x && _positions[i].y == y)
        return true;
    }
    return false;
  }
}