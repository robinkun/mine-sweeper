#pragma once
#include <vector>
#include "Box.h"

using namespace std;

class Board {
private:
  vector<vector<Box>> board;
  int _width;
  int _height;

public:
  Board(int w, int h);
  int width() const;
  int height() const;
};
