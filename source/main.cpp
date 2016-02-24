#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "Test.h"

int main(void) {
  srand((unsigned)time(NULL));
  Board *board = new Board(10, 10);
  Position press(5, 5);
  board->putMine(20, press);
  TestRender t;
  t.b = board;
  t.render();
  return 0;
}
