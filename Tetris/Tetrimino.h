#ifndef TETRIMINO_H
#define TETRIMINO_H

namespace Tetris
{
  // Position of the tetrimino
  struct Position
  {
    int x;
    int y;
  };
  // Shape of the tetrimino
  enum TetriminoType
  {
    I = 1,
    J,
    L,
    O,
    S,
    T,
    Z
  };
  // Tetrimino class
  class Tetrimino
  {
  private:
    TetriminoType _type;
    Position _centerPosition;
    Position _positions[4];

  public:
    // Constructors / Destructor
    Tetrimino();
    Tetrimino(TetriminoType type);
    Tetrimino(TetriminoType type, Position centerPosition);
    ~Tetrimino();
    // Assignment operator
    Tetrimino &operator=(const Tetrimino &other);

    void rotate(short direction);
    void move(short x_amount);
    void move(short x_amount, short y_amount);
  };
}

#endif // TETRIMINO_H