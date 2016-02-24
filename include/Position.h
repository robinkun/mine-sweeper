#pragma once

/*----------------------------
 * 座標
 *----------------------------*/
class Position {
private:
  int _x;
  int _y;

public:
  Position();
  Position(int x, int y);
  void x(int x);
  void y(int y);
  int x() const;
  int y() const;
  int one(int width) const;
};
