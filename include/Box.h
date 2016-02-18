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
  E_MIN,
  E_COVERED,
  E_OPENED,
  E_FLAG,
  E_UNKNOWN,
  E_MAX
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
  bool exterior(Exterior e);
};
