// Copyright 2021 GHA Test Team
#include "../include/TimedDoor.h"

TimedDoor::TimedDoor(int time)
    : iTimeout(time), opened(false), adapter(new DoorTimerAdapter(*this)) {}

bool TimedDoor::isDoorOpened() { return opened; }

void TimedDoor::unlock() {
  opened = true;
  adapter->Timeout();
}

void TimedDoor::lock() { opened = false; }

void TimedDoor::DoorTimeOut() { throw std::string("close the door!"); }

void TimedDoor::throwState() {
  if (opened)
    throw std::string("the door is opened!");
  else
    throw std::string("the door is closed!");
}

int TimedDoor::getTime() { return iTimeout; }

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& _door) : door(_door){};

void Timer::sleep(int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time * 1000));
}

void Timer::tregister(int time, TimerClient* timer) {
  sleep(time);
}

void DoorTimerAdapter::Timeout() {
  Timer tim;
  tim.tregister(door.getTime(), this);
  door.DoorTimeOut();
}
