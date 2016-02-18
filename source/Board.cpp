#include "Board.h"

Board::Board(int w, int h) {
  if(w < 0 || h < 0) {
    w = 1;
    h = 1;
  }
  _width = w;
  _height = h;
  board = vector<vector<Box>>(h);
  for(int i = 0; i < h; i++) {
    board[i] = vector<Box>(w);
    for(int j = 0; j < w; j++) {
      board[i][j] = Box();
    }
  }
}


int Board::width() const {
  return _width;
}


int Board::height() const {
  return _height;
}
