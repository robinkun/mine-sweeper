#include "Board.h"
#include <stdlib.h>
#include <utility>

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

  // 方向ポインタを書き込む
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(positionInRange(Position(j, i-1))) {
        board[i][j].up(&board[i-1][j]);
      }
      if(positionInRange(Position(j+1, i-1))) {
        board[i][j].upright(&board[i-1][j+1]);
      }
      if(positionInRange(Position(j+1, i))) {
        board[i][j].right(&board[i][j+1]);
      }
      if(positionInRange(Position(j+1, i+1))) {
        board[i][j].downright(&board[i+1][j+1]);
      }
      if(positionInRange(Position(j, i+1))) {
        board[i][j].down(&board[i+1][j]);
      }
      if(positionInRange(Position(j-1, i+1))) {
        board[i][j].downleft(&board[i+1][j-1]);
      }
      if(positionInRange(Position(j-1, i))) {
        board[i][j].left(&board[i][j-1]);
      }
      if(positionInRange(Position(j-1, i-1))) {
        board[i][j].upleft(&board[i-1][j-1]);
      }
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
bool Board::putMine(int mine_num, Position press) {
  if(mine_num < 0) return false;
  _mine_num = mine_num;
  if(_mine_num > _width*_height - 1) {
    _mine_num = _width*_height - 1;
  }

  vector<bool> cells(_width*_height, false);

  int press_o = press.one(_width); // 開けた場所
  for(int i = 0; i < _mine_num; i++) {
    int pos = i;
    if(pos >= press_o) {
      pos++;
    }
    cells[i] = true;
  }

  for(int i = 0; i < _width*_height; i++) {
    if(i == press_o) {
      continue;
    }
    int pos = rand()%(_width*_height-1);
    if(pos >= press_o) {
      pos++;
    }
    swap(cells[i], cells[pos]);
  }

  for(int i = 0; i < _width*_height; i++) {
    Position pos;
    pos.two(i, _width);
    printf("%d, %d\n", pos.x(),pos.y());
    // 地雷があるなら
    if(cells[i]) {
      board[pos.y()][pos.x()].setMine();
    }
  }

  return true;
}


/*----------------------------
 * pの座標がボードの範囲内に
 * あるか判定
 *----------------------------*/
bool Board::positionInRange(Position p) const {
  if(p.x() >= 0 && p.x() < _width && p.y() >= 0 && p.y() < _height) {
    return true;
  }
  return false;
}
