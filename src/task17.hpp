#ifndef _TASK_17_HPP_
#define _TASK_17_HPP_

#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Идиотское условие задачи, не решал

namespace Task17 {

void init(std::unordered_map<int, std::vector<int>>& input) {
  int N = 0;
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    int K = 0;
    std::cin >> K;

    std::vector<int> t;
    t.reserve(K);
    for (int j = 0; j < K; ++j) {
      int r = 0;
      std::cin >> r;
      t.push_back(r);
    }

    input[i] = std::move(t);
  }
}

void printResult(bool ok) { std::cout << ok; }

bool solve(const std::unordered_map<int, std::vector<int>>& input) {
  return false;
}

};  // namespace Task17

#endif  // _TASK_17_HPP_