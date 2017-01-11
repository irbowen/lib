
/*
   static_clock.h
   Isaac Bowen

   A simple header-only timing library
 */

#ifndef STATIC_CLOCK_H
#define STATIC_CLOCK_H

#include <ctime>
#include <string>
#include <iostream>

class static_clock {
  public:
  static clock_t begin_time;

  static void start_clock();
  static double end_clock();
  static double end_clock(std::string msg);
};

clock_t static_clock::begin_time;

void static_clock::start_clock() {
  static_clock::begin_time = clock();
}

double static_clock::end_clock() {
  return (double(clock() - begin_time) / CLOCKS_PER_SEC);
}

double static_clock::end_clock(std::string msg) {
  double elapsed_time = static_clock::end_clock();
  std::cout << msg << " [" <<  elapsed_time  << " seconds]\n";
  return elapsed_time;
}

#endif
