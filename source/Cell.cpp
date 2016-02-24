#include "Cell.h"

Cell::Cell() {
  _content = C_NONE;
  _exterior = E_COVERED;
  mine_num = 0;
  _up = _right = _down = _left = nullptr;
}


Cell::Cell(const Cell &obj) {
  _content = obj._content;
  _exterior = obj._exterior;
}


Content Cell::content() const {
  return _content;
}


Exterior Cell::exterior() const {
  return _exterior;
}


bool Cell::content(Content c) {
  if(c < C_NONE || c > C_MINE) {
    return false;
  }
  _content = c;
  return true;
}


void Cell::exterior(Exterior e) {
  _exterior = e;
}


void Cell::up(Cell *u) {
  _up = u;
}


void Cell::right(Cell *r) {
  _right = r;
}


void Cell::down(Cell *d) {
  _down = d;
}


void Cell::left(Cell *l) {
  _left = l;
}


/*----------------------------
 * マスを開く
 *----------------------------*/
void Cell::open() {
  if(exterior() == E_COVERED) {
    exterior(E_OPENED);
  }
}


/*----------------------------
 * マスに旗を立てる
 *----------------------------*/
bool Cell::flag() {
  if(exterior() != E_OPENED) {
    exterior(E_FLAG);
    return true;
  }
  return false;
}


/*----------------------------
 * マスに?をつける
 *----------------------------*/
bool Cell::unknown() {
  if(exterior() != E_OPENED) {
    exterior(E_UNKNOWN);
    return true;
  }
  return false;
}


/*----------------------------
 * マスに地雷を設置
 *----------------------------*/
void Cell::setMine() {
  _content = C_MINE;
}


/*----------------------------
 * マスから地雷を取り除く
 *----------------------------*/
void Cell::setNone() {
  _content = C_NONE;
}
