#pragma once

class GameState {
  public:
    virtual void open() {};
    virtual void close() {};

    virtual void tick() {};
    virtual void draw() {};
};