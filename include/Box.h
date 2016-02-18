#pragma once

class Box {
private:
  int _content; // 中身
  int _exterior; // 外面

public:
  Box();
  int content() const;
  int exterior() const;
  bool content(int c);
  bool exterior(int e);
};
