#ifndef _TASK_62_HPP_
#define _TASK_62_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Task62 {

void solve() {
  std::unordered_set<int> unique_num;

  std::string input, token;
  std::getline(std::cin, input);
  std::stringstream ss(input);

  while (std::getline(ss, token, ' ')) {
    unique_num.insert(std::stoi(token));
  }

  std::cout << unique_num.size();
};

}  // namespace Task62

#endif  // _TASK_62_HPP_