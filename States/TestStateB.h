#include "GameState.h"
#include <iostream>

class TestStateB : public GameState {
  void open();
  void close();

  void tick();
  void draw();
};