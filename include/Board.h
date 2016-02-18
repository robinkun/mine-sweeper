#pragma once
#include <vector>
#include "Box.h"

using namespace std;

/*----------------------------
 * マインスイーパー盤
 *----------------------------*/
class Board {
private:
  vector<vector<Box>> board; // 盤(2次元配列)
  int _width;
  int _height;

public:
  Board(int w, int h);
  void freeBoard();
  int width() const;
  int height() const;
  void setBox(Box box);
};
