
#ifndef STRS_SPLIT_H
#define STRS_SPLIT_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

std::string strip(const std::string& s) {
  std::string result;
  result.reserve(s.length());
  std::remove_copy_if(s.begin(), s.end(),
      std::back_inserter(result),
      std::not1(std::ptr_fun<int, int>(isalnum)));
  return result;
}

auto split_getline(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

auto split2(const std::string &text, char sep) {
  std::vector<std::string> tokens;
  std::size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

auto split3(const std::string& str, const std::string& sep) {
  // First, guesstimate how many pieces will need to split it into
  // auto num_sep = std::count(begin(str), end(str), sep);
  // auto num_sep = 20;
  std::vector<std::string> results;
  //  results.reserve(num_sep);
  // Now, find each portion and push it back into the vector
  size_t start{0}, end{0};
  while (end < str.size()) {
    start = end;
    while (start < str.size() && (sep.find(str[start]) != std::string::npos)) {
      ++start;
    }
    end = start;
    while (end < str.size() && (sep.find(str[end]) == std::string::npos)) {
      ++end;
    }
    if (end - start != 0) {
      results.push_back(std::string(str, start, end-start));
    }
  }
  return results;
}

auto split4(const std::string& str, char sep) {
  // First, guesstimate how many pieces will need to split it into
  auto num_sep = std::count(begin(str), end(str), sep);
  std::vector<std::string> results;
  results.reserve(num_sep);
  // Now, find each portion and push it back into the vector
  size_t start{0}, end{0};
  while (end < str.size() and start != std::string::npos and end != std::string::npos) {
    start = end;
    start = str.find(sep, end);
    end = str.find(sep, start);
    if (end - start > 0 and start != std::string::npos and end != std::string::npos) {
      results.push_back(std::string(str, start, end - start));
    }
    ++end;
  }
  return results;
}

auto split(const std::string &s, char delim) {
  return split_getline(s, delim);
}

#endif
