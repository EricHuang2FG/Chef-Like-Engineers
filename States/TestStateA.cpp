#include "TestStateA.h"

void TestStateA::open() {
  std::cout << "TestStateA opened" << std::endl;
}

void TestStateA::close() {
  std::cout << "TestStateA close" << std::endl;
}

void TestStateA::tick() {
  std::cout << "TestStateA tick" << std::endl;
}

void TestStateA::draw() {
  std::cout << "TestStateA draw" << std::endl;
}