#ifndef _TASK_130_HPP_
#define _TASK_130_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Task130 {

void solve() {
  std::string line, input;
  std::stringstream ss;

  while (std::getline(std::cin, line) && !line.empty()) {
    ss << line << std::endl;
  }
  input = ss.str();

  std::map<char, int> char_counters;
  for (auto c : input) {
    if (c != ' ' && c != '\n' && c != '\r') {
      char_counters[c]++;
    }
  }

  int max_counter =
      std::max_element(
          char_counters.cbegin(), char_counters.cend(),
          [](const auto& p1, const auto& p2) { return p1.second < p2.second; })
          ->second;

  for (int i = max_counter; i > 0; --i) {
    for (const auto& p : char_counters) {
      if (p.second >= i) {
        std::cout << "#";
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  for (const auto& p : char_counters) {
    std::cout << p.first;
  }
};

}  // namespace Task130

#endif  // _TASK_130_HPP_