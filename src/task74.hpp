#ifndef _TASK_74_HPP_
#define _TASK_74_HPP_

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>


namespace Task74 {

void init(std::unordered_map<std::string, int>& input) {
  std::cin >> input["A"];
  std::cin >> input["B"];
  std::cin >> input["C"];
  std::cin >> input["D"];
  std::cin >> input["E"];
}

void printResult(bool ok) {
  if (ok) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}

bool solve(std::unordered_map<std::string, int>& input) {
  std::unordered_map<std::string, int> edges;
  edges["A"] = input["A"];
  edges["B"] = input["B"];
  edges["C"] = input["C"];

  std::unordered_map<std::string, std::pair<int, int>> pair_edges;

  for (const auto& f : edges) {
    for (const auto& s : edges) {
      if (f.first != s.first) {
        pair_edges[f.first + s.first] = std::make_pair(f.second, s.second);
      }
    }
  }

  for (const auto& p : pair_edges) {
    if ((p.second.first <= input["D"]) && (p.second.second <= input["E"])) {
      return true;
    }
  }

  return false;
}

};  // namespace Task74

#endif  // _TASK_74_HPP_