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
  int width();
  int height();
};
