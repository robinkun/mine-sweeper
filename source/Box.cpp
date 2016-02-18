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


bool Box::exterior(Exterior e) {
  if(e <= E_MIN || e >= E_MAX) {
    return false;
  }
  _exterior = e;
  return true;
}
