#include "Cell.h"

Cell::Cell() {
  _content = C_NONE;
  _exterior = E_COVERED;
  mine_num = 0;

  for(int i = 0; i < DIRECTION_NUM; i++) {
    surroundings[i] = nullptr;
  }
}


Cell::Cell(const Cell &obj) {
  if(_content != obj._content) {
    updateSurroundingMineNum();
  }
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


void Cell::up(Cell *p) {
  surroundings[UP] = p;
  updateMineNum();
}


void Cell::upright(Cell *p) {
  surroundings[UPRIGHT] = p;
  updateMineNum();
}


void Cell::right(Cell *p) {
  surroundings[RIGHT] = p;
  updateMineNum();
}


void Cell::downright(Cell *p) {
  surroundings[DOWNRIGHT] = p;
  updateMineNum();
}


void Cell::down(Cell *p) {
  surroundings[DOWN] = p;
  updateMineNum();
}


void Cell::downleft(Cell *p) {
  surroundings[DOWNLEFT] = p;
  updateMineNum();
}


void Cell::left(Cell *p) {
  surroundings[LEFT] = p;
  updateMineNum();
}


void Cell::upleft(Cell *p) {
  surroundings[UPLEFT] = p;
  updateMineNum();
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


/*----------------------------
 * 地雷の数を更新
 *----------------------------*/
void Cell::updateMineNum() {
  mine_num = 0;
  for(int i = 0; i < DIRECTION_NUM; i++) {
    if(surroundings[i]) {
      if(surroundings[i]->_content == C_MINE) {
        mine_num++;
      }
    }
  }
}


/*----------------------------
 * 周りのセルの中のmine_numを更新
 *----------------------------*/
void Cell::updateSurroundMineNum() {
  for(int i = 0; i < DIRECTION_NUM; i++) {
    if(surroundings[i]) {
      surroundings[i]->updateMineNum();
    }
  }
}
