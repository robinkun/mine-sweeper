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
  Exterior _exterior; // 状態

public:
  Cell();
  Content content() const;
  Exterior exterior() const;
  bool content(Content c);
  void exterior(Exterior e);
  void open();
  bool flag();
  bool unknown();
  void setMine();
  void setNone();
};
