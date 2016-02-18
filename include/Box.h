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
class Box {
private:
  Content _content; // 中身
  Exterior _exterior; // 状態

public:
  Box();
  Content content() const;
  Exterior exterior() const;
  bool content(Content c);
  void exterior(Exterior e);
  void open();
};
