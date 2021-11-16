#ifndef TETRIMINO_H
#define TETRIMINO_H

namespace Tetris
{
  // Position of the tetrimino
  struct Position
  {
    Position() {}
    Position(float x, float y) : x(x), y(x) {}
    float x{4};
    float y{0};
    Position &operator=(const Position &other)
    {
      x = other.x;
      y = other.y;
      return *this;
    }
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
  // "Includo" a modo mio la classe TetrisGrid
  class TetrisGrid;
  // Tetrimino class
  class Tetrimino
  {
  private:
    TetriminoType _type;
    Position _pivot;
    Position _positions[4];
    TetrisGrid *_grid;

    void initialize_position(TetriminoType type);

  public:
    // Constructors / Destructor
    Tetrimino();
    Tetrimino(TetriminoType type);
    ~Tetrimino();
    // Assignment operator
    Tetrimino &operator=(const Tetrimino &other);

    void rotate(short times);
    void move(short x_amount, short y_amount = 0);

    bool is_occupied(short x, short y);
  };
}

#endif // TETRIMINO_H