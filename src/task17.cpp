#include "task17.hpp"

#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

void Task17::init(std::unordered_map<std::string, int>& input) {
  std::cin >> input["A"];
  std::cin >> input["B"];
  std::cin >> input["C"];
  std::cin >> input["D"];
  std::cin >> input["E"];
}

void Task17::printResult(bool ok) {
  if (ok) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}

bool Task17::solve(std::unordered_map<std::string, int>& input) {
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
