#pragma once

#include "States/GameState.h"

class GameManager {
  public:
    void tick();
    void draw();

    // add a game state to the stack of states
    void pushState(GameState *gameState);
    // remove a game state from the stack of states
    void popState();
    
    ~GameManager();

  private: 

    class GameStateNode {
      public: 
        GameStateNode(GameState *gameState, GameStateNode *next) {
          this->gameState = gameState;
          this->next = next;
        }

        GameState *gameState = nullptr;
        GameStateNode *next = nullptr;
    };

    GameStateNode *top = nullptr;
};