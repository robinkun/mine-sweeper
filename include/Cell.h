#pragma once

/*----------------------------
 * 盤のマスの中身
 *----------------------------*/
enum Content {
  C_NONE = 0,
  C_MINE = 9
};


/*----------------------------
 * 盤のマスの状態
 *----------------------------*/
enum Exterior {
  E_COVERED,
  E_OPENED,
  E_FLAG,
  E_UNKNOWN,
};


/*----------------------------
 * 盤のマス
 *----------------------------*/
class Cell {
private:
  Content _content; // 中身
  Exterior _exterior; // 外観
  int mine_num;
  Cell *_up;
  Cell *_right;
  Cell *_down;
  Cell *_left;

public:
  Cell();
  Cell(const Cell &obj);
  Content content() const;
  Exterior exterior() const;
  bool content(Content);
  void exterior(Exterior);
  void up(Cell *);
  void right(Cell *);
  void down(Cell *);
  void left(Cell *);
  void open();
  bool flag();
  bool unknown();
  void setMine();
  void setNone();
};
