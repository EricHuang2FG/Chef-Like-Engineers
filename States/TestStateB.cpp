#include "TestStateB.h"

void TestStateB::open() {
  std::cout << "TestStateB opened" << std::endl;
}

void TestStateB::close() {
  std::cout << "TestStateB close" << std::endl;
}

void TestStateB::tick() {
  std::cout << "TestStateB tick" << std::endl;
}

void TestStateB::draw() {
  std::cout << "TestStateB draw" << std::endl;
}