
/*
   Isaac Bowen
   helper.h

   Some handy helper functions
 */

#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

void print(const std::vector<std::string>& v) {
  std::ostringstream oss;
  for (auto& s : v) {
    oss << s << " ";
  }
  std::cout << oss.str() << std::endl;
}

#endif
