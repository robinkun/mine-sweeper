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
 * 方向
 *----------------------------*/
enum Direction {
  UP,
  UPRIGHT,
  RIGHT,
  DOWNRIGHT,
  DOWN,
  DOWNLEFT,
  LEFT,
  UPLEFT,
  DIRECTION_NUM
};


/*----------------------------
 * 盤のマス
 *----------------------------*/
class Cell {
private:
  Content _content; // 中身
  Exterior _exterior; // 外観
  int _mine_num;
  Cell *surroundings[DIRECTION_NUM];

  void reflexiveOpen(Cell *);

public:
  Cell();
  Cell(const Cell &obj);
  Content content() const;
  Exterior exterior() const;
  int mine_num();
  bool content(Content);
  void exterior(Exterior);

  void up(Cell *);
  void upright(Cell *);
  void right(Cell *);
  void downright(Cell *);
  void down(Cell *);
  void downleft(Cell *);
  void left(Cell *);
  void upleft(Cell *);

  void open();
  bool flag();
  bool unknown();
  void setMine();
  void setNone();
  void updateMineNum();
  void updateSurroundMineNum();

  bool isOpened();
  bool isMine();
};
