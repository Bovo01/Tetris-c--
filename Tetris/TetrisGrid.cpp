#include "TetrisGrid.h"
#include "keys.cpp"
#include <ctime>

namespace Tetris
{
  TetrisGrid::TetrisGrid()
  {
    srand((unsigned)time(0)); // Creo un seed random
    initialize_matrix();      // Inizializzo la matrice
    // Inizializzo i prossimi blocchi
    _nextTetriminos = new int[_nextTetriminosNumber];
    for (int i = 0; i < _nextTetriminosNumber; i++)
    {
      _nextTetriminos[i] = rand() % 7;
    }
    _currentTetrimino = *(new Tetrimino(static_cast<TetriminoType>(rand() % 7)));
  }
  TetrisGrid::~TetrisGrid()
  {
    delete[] _nextTetriminos;
  }

  void TetrisGrid::initialize_matrix(void)
  {
    _grid = new int[_width * _height];
    for (int i = 0; i < _width * _height; i++)
    {
      _grid[i] = 0;
    }
  }

  void TetrisGrid::next_tetrimino(void)
  {
    _currentTetrimino = *(new Tetrimino(static_cast<TetriminoType>(_nextTetriminos[0])));
    for (int i = 0; i < _nextTetriminosNumber - 1; i++)
    {
      _nextTetriminos[i] = _nextTetriminos[i + 1];
    }
    _nextTetriminos[_nextTetriminosNumber - 1] = rand() % 7;
  }

  // Getters
  int TetrisGrid::width(void) const { return _width; }
  int TetrisGrid::height(void) const { return _height; }
  int TetrisGrid::get(int i, int j) const
  {
    return _grid[i + j * _width];
  }

  // Graphics
  void TetrisGrid::draw(void) const
  {
    std::cout << *this << std::endl;
  }
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
        if (grid.get(i - 1, j - 1) == 0)
          os << ' ';
        else
          os << grid.get(i - 1, j - 1); //TODO Converti in carattere colorato
      }
      os << std::endl;
    }
    return os;
  }
  // Events
  void key_pressed(int key)
  {
    using namespace Tetris::KEYS;
    switch (key)
    {
    case KEY_SPACE:
      // TODO Rotate inverse
      break;
    case KEY_UP:
    case KEY_W:
      // TODO Rotate
      break;
    case KEY_DOWN:
    case KEY_S:
      // TODO Move down
      break;
    case KEY_LEFT:
    case KEY_A:
      // TODO Move left
      break;
    case KEY_RIGHT:
    case KEY_D:
      // TODO Move right
      break;
    case ESC:
      // TODO Open menu
      break;
    }
  }
}