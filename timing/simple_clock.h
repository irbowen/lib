
/*
   simple_clock.h
   Isaac Bowen

   A simple header-only timing library

 */

#ifndef SIMPLE_CLOCK_H
#define SIMPLE_CLOCK_H

#include <string>

class simple_clock {

  static clock_t begin_time, end_time;


  public:
  static void start_clock();
  static double end_clock();
  static double end_clock(std::string msg);
};

clock_t simple_clock::begin_time;
clock_t simple_clock::end_time;

void simple_clock::start_clock() {
  simple_clock::begin_time = clock();
}

double simple_clock::end_clock() {
  end_time = clock();
  return (double(end_time - begin_time) / CLOCKS_PER_SEC);
}

double simple_clock::end_clock(std::string msg) {
  end_time = clock();
  double elapsed_time = double(end_time - begin_time) / CLOCKS_PER_SEC;
  std::cout << msg << "[" <<  elapsed_time  << " seconds]\n";
  return elapsed_time;
}

#endif
