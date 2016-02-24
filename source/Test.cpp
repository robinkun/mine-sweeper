#include "Test.h"
#include <stdio.h>

void TestRender::render() {
  for(int i = 0; i < b->height(); i++) {
    for(int j = 0; j < b->width(); j++) {
      printf("%2d", b->cell(j, i)->content());
    }
    printf("\n");
  }
  puts("");

  for(int i = 0; i < b->height(); i++) {
    for(int j = 0; j < b->width(); j++) {
      printf("%2d", b->cell(j, i)->mine_num());
    }
    printf("\n");
  }
  puts("");

  for(int i = 0; i < b->height(); i++) {
    for(int j = 0; j < b->width(); j++) {
      printf("%2d", b->cell(j, i)->exterior());
    }
    printf("\n");
  }
  puts("");
}
