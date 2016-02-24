#include "Position.h"

Position::Position() {
  _x = _y = 0;
}


Position::Position(int x, int y) {
  _x = x;
  _y = y;
}


void Position::x(int x) {
  _x = x;
}


void Position::y(int y) {
  _y = y;
}


int Position::x() const {
  return _x;
}


int Position::y() const {
  return _y;
}


/*----------------------------
 * 2次元座標に変換して代入
 *----------------------------*/
void Position::two(int o, int width) {
  _x = o%width;
  _y = o/width;
}


/*----------------------------
 * 1次元座標に変換
 *----------------------------*/
int Position::one(int width) const {
  return _x + _y*width;
}
