#include "TetrisGrid.h"
#include "keys.cpp"
#include <ctime>

namespace Tetris
{
  // Constructor
  TetrisGrid::TetrisGrid()
  {
    srand((unsigned)time(0)); // Creo un seed random
    initialize_matrix();      // Inizializzo la matrice
    // Inizializzo i prossimi blocchi
    _nextTetriminos = new int[_nextTetriminosNumber];
    for (int i = 0; i < _nextTetriminosNumber; i++)
    {
      _nextTetriminos[i] = rand() % 7 + 1;
    }
    _currentTetrimino =
        {static_cast<TetriminoType>(rand() % 7 + 1), this};
  }
  // Destructor
  TetrisGrid::~TetrisGrid()
  {
    delete[] _grid;
    delete[] _nextTetriminos;
  }
  // Inizializzo la matrice
  void TetrisGrid::initialize_matrix(void)
  {
    _grid = new int[_width * _height];
    for (int i = 0; i < _width * _height; i++)
    {
      _grid[i] = 0;
    }
  }
  // Inizializzo il prossimo blocco
  void TetrisGrid::next_tetrimino(void)
  {
    _currentTetrimino =
        {static_cast<TetriminoType>(rand() % 7 + 1), this};
    for (int i = 0; i < _nextTetriminosNumber - 1; i++)
    {
      _nextTetriminos[i] = _nextTetriminos[i + 1];
    }
    _nextTetriminos[_nextTetriminosNumber - 1] = rand() % 7 + 1;
  }

  // Getters
  int TetrisGrid::width(void) const { return _width; }
  int TetrisGrid::height(void) const { return _height; }
  int TetrisGrid::get(int i, int j) const
  {
    return _grid[i + j * _width];
  }
  Tetrimino TetrisGrid::current_tetrimino(void) const
  {
    return _currentTetrimino;
  }
  // Methods
  int TetrisGrid::speed(void) const { return 1000 / _level; }
  bool TetrisGrid::is_game_over(void) const { return false; } // TODO check if game is over

  // Graphics
  std::ostream &operator<<(std::ostream &os, const TetrisGrid &grid)
  {
    // Disegno il gioco (con una cornice) per righe
    for (int i = 0; i < grid.height() + 2; i++)
    {
      for (int j = 0; j < grid.width() + 2; j++)
      {
        // Cornice sopra e sotto
        if ((i == 0 || i == grid.height() + 1) ||
            (j == 0 || j == grid.width() + 1))
        {
          os << '#';
          continue;
        }
        // TODO output blocco in base al tipo salvato in _grid
        if (grid.current_tetrimino().is_occupied(j - 1, i - 1))
          os << 'X';
        else
        {
          if (grid.get(i - 1, j - 1) == 0)
            os << ' ';
          else
            os << grid.get(i - 1, j - 1); //TODO Converti in carattere colorato
        }
      }
      os << std::endl;
    }
    return os;
  }
  // KeyPressed event
  void TetrisGrid::key_pressed(int key)
  {
    using namespace Tetris::KEYS;
    switch (key)
    {
    case KEY_SPACE:
      // TODO Rotate inverse
      rotate_counter();
      break;
    case KEY_UP:
    case KEY_W:
      // TODO Rotate
      rotate();
      break;
    case KEY_DOWN:
    case KEY_S:
      move_down();
      break;
    case KEY_LEFT:
    case KEY_A:
      move_left();
      break;
    case KEY_RIGHT:
    case KEY_D:
      move_right();
      break;
    case ESC:
      // TODO Open menu
      break;
    }
  }

  // Tetrimino modification
  void TetrisGrid::move_right(void) { _currentTetrimino.move(1); }
  void TetrisGrid::move_left(void) { _currentTetrimino.move(-1); }
  void TetrisGrid::move_down(void) { _currentTetrimino.move(0, 1); }
  void TetrisGrid::rotate(void) { _currentTetrimino.rotate(1); }
  void TetrisGrid::rotate_counter(void) { _currentTetrimino.rotate(-1); }
}