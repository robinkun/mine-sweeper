#include "Box.h"

Box::Box() {
  _content = C_NONE;
  _exterior = E_COVERED;
}


Content Box::content() const {
  return _content;
}


Exterior Box::exterior() const {
  return _exterior;
}


bool Box::content(Content c) {
  if(c < C_NONE || c > C_MINE) {
    return false;
  }
  _content = c;
  return true;
}


void Box::exterior(Exterior e) {
  _exterior = e;
}


/*----------------------------
 * マスを開く
 *----------------------------*/
void Box::open() {
  if(exterior() == E_COVERED) {
    exterior(E_OPENED);
  }
}


/*----------------------------
 * マスに旗を立てる
 *----------------------------*/
bool Box::flag() {
  if(exterior() != E_OPENED) {
    exterior(E_FLAG);
    return true;
  }
  return false;
}


/*----------------------------
 * マスに?をつける
 *----------------------------*/
bool Box::unknown() {
  if(exterior() != E_OPENED) {
    exterior(E_UNKNOWN);
    return true;
  }
  return false;
}


/*----------------------------
 * マスに地雷を設置
 *----------------------------*/
void Box::setMine() {
  _content = C_MINE;
}


/*----------------------------
 * マスから地雷を取り除く
 *----------------------------*/
void Box::setNone() {
  _content = C_NONE;
}
