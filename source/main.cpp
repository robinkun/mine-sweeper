#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "Test.h"

int main(void) {
  srand((unsigned)time(NULL));
  Board *board = new Board(10, 10);
  Position press(5, 5);
  board->putMine(50, press);
  TestRender t;
  t.b = board;
  t.render();
  //board->reflexiveOpen(3, 3);
  t.render();
  return 0;
}
