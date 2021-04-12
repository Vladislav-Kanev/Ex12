// Copyright 2021 GHA Test Team
#include <iostream>
#include "../include/TimedDoor.h"

int main() {
  TimedDoor tDoor(5);
  try {
    tDoor.lock();
    tDoor.throwState();
  } catch (std::string message) {
    std::cout << message;
  }
  return 0;
}
