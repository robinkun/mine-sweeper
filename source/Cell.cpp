#include "Cell.h"

Cell::Cell() {
  _content = C_NONE;
  _exterior = E_COVERED;
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
