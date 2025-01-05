#include "GameManager.h"

void GameManager::tick() {
  // if there is no game state in the stack, then do nothing
  if(top == nullptr || top->gameState == nullptr) {
    return;
  }

  // propagate the tick to the current state
  top->gameState->tick();
}

void GameManager::draw() {
  // if there is no game state in the stack, then do nothing
  if(top == nullptr || top->gameState == nullptr) {
    return;
  }

  // propagate the draw to the current state
  top->gameState->draw();
}

void GameManager::pushState(GameState *gameState) {
  // if we are pushing a null pointer don't do anything cuz that'd be stupid
  if(gameState == nullptr) {
    return;
  }

  // if there is already a state active, then close it
  if(this->top != nullptr && this->top->gameState != nullptr) {
    this->top->gameState->close();
  }

  // create a new node and set it to the top
  this->top = new GameStateNode(gameState, this->top);

  // open the new game state
  gameState->open();
}

void GameManager::popState() {
  // if there is nothing on the stack don't do anything
  if(this->top == nullptr) {
    return;
  }

  // get the node to be removed
  GameStateNode *removeGameState = this->top;

  // if it has a valid game state, then close it as we are removing it
  if(removeGameState->gameState != nullptr) {
    removeGameState->gameState->close();
  }

  // set the top to be the next game state in the list
  this->top = removeGameState->next;

  // if there was another game state in the stack and is valid, then open it
  if(this->top != nullptr && this->top->gameState != nullptr) {
    this->top->gameState->open();
  }

  // delete the previous top game state set to be remove
  delete removeGameState;
}

GameManager::~GameManager() {
  while(this->top != nullptr) {
    popState();
  }
}