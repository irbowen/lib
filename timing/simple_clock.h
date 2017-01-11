
/*
   simple_clock.h
   Isaac Bowen

   A simple header-only timing library
 */

#ifndef SIMPLE_CLOCK_H
#define SIMPLE_CLOCK_H

#include <ctime>

class simple_clock {
  public:
  clock_t begin_time;
  void start_clock();
  double end_clock();
};

void simple_clock::start_clock() {
  simple_clock::begin_time = clock();
}

double simple_clock::end_clock() {
  return (double(clock() - begin_time) / CLOCKS_PER_SEC);
}

#endif
