#include "Tetrimino.h"

namespace Tetris
{
  // Constructors
  Tetrimino::Tetrimino(TetriminoType type) : _type(type) {}
  Tetrimino::Tetrimino(TetriminoType type, Position position) : _type(type), _position(position) {}
  // Destructor
  Tetrimino::~Tetrimino() {}

}