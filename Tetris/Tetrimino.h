#ifndef TETRIMINO_H
#define TETRIMINO_H

namespace Tetris
{
  // Position of the tetrimino
  struct Position
  {
    Position() {}
    Position(short x, short y) : x(x), y(y) {}
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
    NONE = 0,
    I = 1,
    J,
    L,
    O,
    S,
    T,
    Z
  };
  enum TetriminoColor
  {
    COLOR_NONE = -1,
    COLOR_I = 0x33,
    COLOR_J = 0x11,
    COLOR_L = 0xCC,
    COLOR_O = 0xEE,
    COLOR_S = 0xAA,
    COLOR_T = 0xDD,
    COLOR_Z = 0x44
  };
  int get_color_from_tetrimino(TetriminoType tetrimino_type);
  int get_color_from_tetrimino(int tetrimino_type);
  // "Includo" a modo mio la classe TetrisGrid
  class TetrisGrid;
  // Tetrimino class
  class Tetrimino
  {
  private:
    TetriminoType _type;
    float _pivot_x;
    float _pivot_y;
    Position _positions[4];
    TetrisGrid *_grid;

    void initialize_position(TetriminoType type);

  public:
    // Constructor / Destructor
    Tetrimino();
    Tetrimino(TetriminoType type, TetrisGrid *grid);
    ~Tetrimino();
    // Getters
    TetriminoType type(void) const;
    Position *occupied_positions(void);
    // Assignment operator
    Tetrimino &operator=(const Tetrimino &other);

    // Conditionals
    bool is_occupied(short x, short y);
    bool can_rotate(short times) const;
    bool can_move(short x_amount, short y_amount = 0) const;
    // Actions
    bool rotate(short times);
    bool move(short x_amount, short y_amount = 0);
    int delete_lines(void);
  };
}

#endif // TETRIMINO_H