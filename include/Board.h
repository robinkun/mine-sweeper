#pragma once
#include <vector>
#include "Cell.h"
#include "Position.h"

using namespace std;

/*----------------------------
 * マインスイーパー盤
 *----------------------------*/
class Board {
private:
  int _width;
  int _height;
  int _mine_num;

public:
  vector<vector<Cell>> board; // 盤(2次元配列)
  Board(int w, int h);
  void freeBoard();
  bool putMine(int mine_num, Position press);
  int width() const;
  int height() const;
  int mine_num() const;
  bool positionInRange(Position p) const;
};
