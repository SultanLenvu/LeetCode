#ifndef _TASK_103_HPP_
#define _TASK_103_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace Task103 {

void solve() {
  std::unordered_map<std::string, int> input;
  std::cin >> input["A"] >> input["B"] >> input["C"] >> input["D"];

  std::vector<std::pair<int, int>> possible_dems;
  possible_dems.emplace_back((input["A"] + input["D"]),
                             std::max(input["B"], input["C"]));
  possible_dems.emplace_back((input["A"] + input["C"]),
                             std::max(input["B"], input["D"]));
  possible_dems.emplace_back((input["B"] + input["D"]),
                             std::max(input["A"], input["C"]));
  possible_dems.emplace_back((input["B"] + input["C"]),
                             std::max(input["A"], input["D"]));

  auto min_dems =
      std::min_element(possible_dems.cbegin(), possible_dems.cend(),
                       [](const auto& d1, const auto& d2) {
                         return d1.first * d1.second < d2.first * d2.second;
                       });

  std::cout << min_dems->first << " " << min_dems->second;
};

}  // namespace Task103

#endif  // _TASK_103_HPP_