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
  vector<vector<Cell>> board; // 盤(2次元配列)

public:
  Board(int w, int h);
  Cell *cell(Position p);
  Cell *cell(int x, int y);
  void freeBoard();
  bool putMine(int mine_num, Position press);
  int width() const;
  int height() const;
  int mine_num() const;
  void reflexiveOpen(Position p);
  void reflexiveOpen(int x, int y);
  bool positionInRange(Position p) const;
  bool positionInRange(int x, int y) const;
};
