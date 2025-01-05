#include "GameState.h"
#include <iostream>

class TestStateA : public GameState {
  void open();
  void close();

  void tick();
  void draw();
};