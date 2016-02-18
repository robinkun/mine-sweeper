#include "Box.h"

int Box::content() const {
  return _content;
}


int Box::exterior() const {
  return _exterior;
}


bool Box::content(int c) {
  _content = c;
  return true;
}


bool Box::exterior(int e) {
  _exterior = e;
  return true;
}
