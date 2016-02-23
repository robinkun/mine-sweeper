#pragma once
#include <vector>
#include "Cell.h"

using namespace std;

/*----------------------------
 * マインスイーパー盤
 *----------------------------*/
class Board {
private:
  vector<vector<Cell>> board; // 盤(2次元配列)
  int _width;
  int _height;
  int _mine_num;

public:
  Board(int w, int h);
  void freeBoard();
  bool putMine(int mine_num);
  int width() const;
  int height() const;
  int mine_num() const;
};
