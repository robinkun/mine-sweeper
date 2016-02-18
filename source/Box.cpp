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
  _content = c;
  return true;
}


bool Box::exterior(Exterior e) {
  _exterior = e;
  return true;
}
