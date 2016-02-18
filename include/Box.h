#pragma once

enum Content {
  C_NONE = 0,
  C_MINE = 9
};


enum Exterior {
  E_COVERED,
  E_OPENED,
  E_FLAG,
  E_UNKNOWN
};


class Box {
private:
  Content _content; // 中身
  Exterior _exterior; // 外面

public:
  Box();
  Content content() const;
  Exterior exterior() const;
  bool content(Content c);
  bool exterior(Exterior e);
};
