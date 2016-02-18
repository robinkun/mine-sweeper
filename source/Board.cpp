#include "Board.h"

Board::Board(int w, int h) {
  if(w < 0 || h < 0) {
    w = 1;
    h = 1;
  }
  _width = w;
  _height = h;

  // 幅w、高さhでマスを確保
  freeBoard();
  board = vector<vector<Box>>(h);
  for(int i = 0; i < h; i++) {
    board[i] = vector<Box>(w);
    for(int j = 0; j < w; j++) {
      board[i][j] = Box();
    }
  }
}

void Board::freeBoard() {
  for(unsigned int i = 0; i < board.size(); i++) {
    board[i].~vector();
  }
  board.~vector();
}


int Board::width() const {
  return _width;
}


int Board::height() const {
  return _height;
}


void Board::setBox(Box box) {
}
