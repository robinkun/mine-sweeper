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
  board = vector<vector<Cell>>(h);
  for(int i = 0; i < h; i++) {
    board[i] = vector<Cell>(w);
    for(int j = 0; j < w; j++) {
      board[i][j] = Cell();
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(i > 0)
        board[i][j].up(&board[i-1][j]);
      if(i > 0 && j < w-1)
        board[i][j].upright(&board[i-1][j+1]);
      if(j < w-1)
        board[i][j].right(&board[i][j+1]);
      if(i < h-1 && j < w-1)
        board[i][j].downright(&board[i+1][j+1]);
      if(i < h-1)
        board[i][j].down(&board[i+1][j]);
      if(i < h-1 && j > 0)
        board[i][j].downleft(&board[i+1][j-1]);
      if(j > 0)
        board[i][j].left(&board[i][j-1]);
      if(i > 0 && j > 0)
        board[i][j].upleft(&board[i-1][j-1]);
    }
  }
}


/*----------------------------
 * マインスイーパー盤を開放
 *----------------------------*/
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


int Board::mine_num() const {
  return _mine_num;
}


/*----------------------------
 * マインスイーパー盤に地雷を
 * 配置
 *----------------------------*/
bool Board::putMine(int mine_num) {
  if(mine_num < 0) return false;
  _mine_num = mine_num;
  if(_mine_num > _width*_height - 1) {
    _mine_num = _width*_height - 1;
  }

  for(int i = 0, mine = 0; i < _height; i++) {
    for(int j = 0; j < _width; j++, mine++) {
      board[i][j].setMine();
      if(mine >= mine_num) {
        i = _height; // ループを抜ける
        break;
      }
    }
  }

  return true;
}
