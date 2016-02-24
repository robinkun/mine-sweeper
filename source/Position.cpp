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
