#include <math.h>
#include "Tetrimino.h"
#include "TetrisGrid.h"

#define _USE_MATH_DEFINES // Include M_PI

namespace Tetris
{
  // Constructors
  Tetrimino::Tetrimino() {}
  Tetrimino::Tetrimino(TetriminoType type, TetrisGrid *grid) : _type(type), _grid(grid)
  {
    initialize_pivot((int)_grid->width() / 2);
    initialize_position();
    for (int i = 0; i < 4; i++)
    {
      if (_grid->get(_positions[i].x, _positions[i].y) != TetriminoType::NONE)
      {
        _grid->game_over();
        break;
      }
    }
  }
  Tetrimino::Tetrimino(TetriminoType type, short x_offset, short y_offset)
      : _type(type)
  {
    initialize_pivot(x_offset, y_offset);
    initialize_position();
  }
  // Destructor
  Tetrimino::~Tetrimino() {}

  // Initialize pivot
  void Tetrimino::initialize_pivot(short x_offset, short y_offset)
  {
    switch (_type)
    {
    case I:
      _pivot_x = x_offset - .5;
      _pivot_y = y_offset + .5;
      break;
    case J:
      _pivot_x = x_offset;
      _pivot_y = y_offset + 1;
      break;
    case L:
      _pivot_x = x_offset;
      _pivot_y = y_offset + 1;
      break;
    case O:
      _pivot_x = x_offset - .5;
      _pivot_y = y_offset + .5;
      break;
    case S:
      _pivot_x = x_offset;
      _pivot_y = y_offset + 1;
      break;
    case T:
      _pivot_x = x_offset;
      _pivot_y = y_offset + 1;
      break;
    case Z:
      _pivot_x = x_offset;
      _pivot_y = y_offset + 1;
    }
  }

  // Initialize blocks
  void Tetrimino::initialize_position(void)
  {
    switch (_type)
    {
    case I:
      _positions[0] = Position(_pivot_x - 1.5, _pivot_y - .5);
      _positions[1] = Position(_pivot_x - .5, _pivot_y - .5);
      _positions[2] = Position(_pivot_x + .5, _pivot_y - .5);
      _positions[3] = Position(_pivot_x + 1.5, _pivot_y - .5);
      break;
    case J:
      _positions[0] = Position(_pivot_x - 1, _pivot_y);
      _positions[1] = Position(_pivot_x, _pivot_y);
      _positions[2] = Position(_pivot_x + 1, _pivot_y);
      _positions[3] = Position(_pivot_x + 1, _pivot_y - 1);
      break;
    case L:
      _positions[0] = Position(_pivot_x - 1, _pivot_y);
      _positions[1] = Position(_pivot_x, _pivot_y);
      _positions[2] = Position(_pivot_x + 1, _pivot_y);
      _positions[3] = Position(_pivot_x - 1, _pivot_y - 1);
      break;
    case O:
      _positions[0] = Position(_pivot_x - .5, _pivot_y - .5);
      _positions[1] = Position(_pivot_x + .5, _pivot_y - .5);
      _positions[2] = Position(_pivot_x - .5, _pivot_y + .5);
      _positions[3] = Position(_pivot_x + .5, _pivot_y + .5);
      break;
    case S:
      _positions[0] = Position(_pivot_x - 1, _pivot_y);
      _positions[1] = Position(_pivot_x, _pivot_y);
      _positions[2] = Position(_pivot_x, _pivot_y - 1);
      _positions[3] = Position(_pivot_x + 1, _pivot_y - 1);
      break;
    case T:
      _positions[0] = Position(_pivot_x + 1, _pivot_y);
      _positions[1] = Position(_pivot_x, _pivot_y);
      _positions[2] = Position(_pivot_x, _pivot_y - 1);
      _positions[3] = Position(_pivot_x - 1, _pivot_y);
      break;
    case Z:
      _positions[0] = Position(_pivot_x + 1, _pivot_y);
      _positions[1] = Position(_pivot_x, _pivot_y);
      _positions[2] = Position(_pivot_x, _pivot_y - 1);
      _positions[3] = Position(_pivot_x - 1, _pivot_y - 1);
    }
  }

  // Getters
  TetriminoType Tetrimino::type(void) const { return _type; }
  Position *Tetrimino::occupied_positions(void) { return &_positions[0]; };
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

  // Conditionals
  // Returns true if the tetrimino occupies that position
  bool Tetrimino::is_occupied(short x, short y)
  {
    for (int i = 0; i < 4; i++)
    {
      if (_positions[i].x == x && _positions[i].y == y)
        return true;
    }
    return false;
  }
  // Returns false if the position is occupied by a block
  bool Tetrimino::can_move(short x_amount, short y_amount) const
  {
    for (int i = 0; i < 4; i++)
    {
      short x = _positions[i].x + x_amount;
      short y = _positions[i].y + y_amount;
      if (_grid->get(x, y) != NONE || x < 0 || y < 0 || x >= _grid->width() || y >= _grid->height())
        return false;
    }
    return true;
  }
  // Returns false if the rotation brings the tetrimino in a position occupied by a block
  bool Tetrimino::can_rotate(short times) const
  {
    double angle = (times % 4) * M_PI / 2;
    int sen = round(sin(angle));
    int cose = round(cos(angle));
    for (int i = 0; i < 4; i++)
    {
      short x = _pivot_x + (cose * (_positions[i].x - _pivot_x) - sen * (_positions[i].y - _pivot_y));
      short y = _pivot_y + (sen * (_positions[i].x - _pivot_x) + cose * (_positions[i].y - _pivot_y));
      if (_grid->get(x, y) != NONE || x < 0 || y < 0 || x >= _grid->width() || y >= _grid->height())
        return false;
    }
    return true;
  }

  // Move the tetrimino
  bool Tetrimino::move(short x_amount, short y_amount)
  {
    if (!can_move(x_amount, y_amount))
      return false;
    _pivot_x += x_amount;
    _pivot_y += y_amount;
    for (int i = 0; i < 4; i++)
    {
      _positions[i].x += x_amount;
      _positions[i].y += y_amount;
    }
    return true;
  }

  // Rotate the tetrimino
  bool Tetrimino::rotate(short times = 1)
  {
    if (!can_rotate(times))
      return false;
    double angle = (times % 4) * M_PI / 2;
    int sen = round(sin(angle));
    int cose = round(cos(angle));
    for (int i = 0; i < 4; i++)
    {
      // I have to save x and y coordinates because otherwise they will be overwritten
      short x = _positions[i].x;
      short y = _positions[i].y;
      _positions[i].x = _pivot_x + (cose * (x - _pivot_x) - sen * (y - _pivot_y));
      _positions[i].y = _pivot_y + (sen * (x - _pivot_x) + cose * (y - _pivot_y));
    }
    return true;
  }
}