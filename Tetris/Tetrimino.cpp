#include "Tetrimino.h"

namespace Tetris
{
  // Constructors
  Tetrimino::Tetrimino() {}
  Tetrimino::Tetrimino(TetriminoType type) : _type(type) {}
  Tetrimino::Tetrimino(TetriminoType type, Position centerPosition) : _type(type), _centerPosition(centerPosition) {}
  // Destructor
  Tetrimino::~Tetrimino() {}

  // Assignment operator
  Tetrimino &Tetrimino::operator=(const Tetrimino &other)
  {
    _type = other._type;
    _centerPosition = other._centerPosition;
    return *this;
  }
}