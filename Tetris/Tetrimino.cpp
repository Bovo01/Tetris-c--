#include <math.h>
#include "Tetrimino.h"
#include "TetrisGrid.h"

#define _USE_MATH_DEFINES // Include M_PI

namespace Tetris
{
  // Constructors
  Tetrimino::Tetrimino() {}
  Tetrimino::Tetrimino(TetriminoType type) : _type(type)
  {
    initialize_position(type);
  }
  // Destructor
  Tetrimino::~Tetrimino() {}

  // Initialize pivot and blocks
  void Tetrimino::initialize_position(TetriminoType type)
  {
    switch (type)
    {
    case I:
      _pivot = Position(((int)_grid->width() / 2) - .5, 0);
      _positions[0] = Position(_pivot.x - 1.5, 0);
      _positions[1] = Position(_pivot.x - .5, 0);
      _positions[2] = Position(_pivot.x + .5, 0);
      _positions[3] = Position(_pivot.x + 1.5, 0);
      break;
    case J:
      _pivot = Position((int)_grid->width() / 2, 0);
      _positions[0] = Position(_pivot.x - 1, 1);
      _positions[1] = Position(_pivot.x, 1);
      _positions[2] = Position(_pivot.x + 1, 1);
      _positions[3] = Position(_pivot.x + 1, 0);
      break;
    case L:
      _pivot = Position((int)_grid->width() / 2, 0);
      _positions[0] = Position(_pivot.x - 1, 1);
      _positions[1] = Position(_pivot.x, 1);
      _positions[2] = Position(_pivot.x + 1, 1);
      _positions[3] = Position(_pivot.x - 1, 0);
      break;
    case O:
      _pivot = Position(((int)_grid->width() / 2) - .5, 0);
      _positions[0] = Position(0, 0);
      _positions[1] = Position(0, 1);
      _positions[2] = Position(1, 0);
      _positions[3] = Position(1, 1);
      break;
    case S: // TODO Posizione iniziale S
      _pivot = Position(0, 0);
      _positions[0] = Position(0, 0);
      _positions[1] = Position(0, 1);
      _positions[2] = Position(1, 1);
      _positions[3] = Position(1, 2);
      break;
    case Z: // TODO Posizione iniziale Z

      break;
    case T: // TODO Posizione iniziale T
      _pivot = Position(0, 0);
      _positions[0] = Position(0, 0);
      _positions[1] = Position(0, 1);
      _positions[2] = Position(0, 2);
    }
  }

  // Assignment operator
  Tetrimino &Tetrimino::operator=(const Tetrimino &other)
  {
    _type = other._type;
    _pivot = other._pivot;
    return *this;
  }

  // Move the tetrimino
  void Tetrimino::move(short x_amount, short y_amount)
  {
    _pivot.x += x_amount;
    _pivot.y += y_amount;
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
      _positions[i].x = _pivot.x + (cos(angle) * (_positions[i].x - _pivot.x) - sin(angle) * (_positions[i].y - _pivot.y));
      _positions[i].y = _pivot.y + (sin(angle) * (_positions[i].x - _pivot.x) + cos(angle) * (_positions[i].y - _pivot.y));
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