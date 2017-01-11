
/*
   simple_clock_manager.h
   Isaac Bowen

   A simple header-only timing library
 */

#ifndef SIMPLE_CLOCK_MANAGER_H
#define SIMPLE_CLOCK_MANAGER_H

#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include "simple_clock.h"

using namespace std;

class simple_clock_manager {
  vector<pair<string, clock_t>> clocks;
  public:
  void start_clock(string key);
  double end_clock(string key);
};

void simple_clock_manager::start_clock(string key) {
  clocks.push_back(make_pair(key, clock()));
}

double simple_clock_manager::end_clock(string key) {
  double end_clock = clock();
  auto clock_pair = find_if(begin(clocks), end(clocks), [key] (auto elem) {
      return elem.first == key;});
  auto begin_clock = clock_pair->second;
  double elasped_time = (double(end_clock - begin_clock) / CLOCKS_PER_SEC);
  return elasped_time;
}

#endif
