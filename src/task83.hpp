#ifndef _TASK_83_HPP_
#define _TASK_83_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace Task130 {

void init(std::map<int, int>& key_counter, std::vector<int>& sequence) {
  int n;  // количество клавиш
  std::cin >> n;

  // Считываем максимальное количество нажатий для каждой клавиши
  for (int i = 1; i <= n; i++) {
    std::cin >> key_counter[i];
  }

  int k;  // общее количество нажатий
  std::cin >> k;
  sequence.resize(k);

  // Считываем последовательность нажатых клавиш

  for (int i = 0; i < k; i++) {
    std::cin >> sequence[i];
  }
}

void solve() {
  std::map<int, int> key_counter;
  std::vector<int> sequence;
  init(key_counter, sequence);

  for (const auto& key : sequence) {
    --key_counter[key];
  }

  for (auto k : key_counter) {
    std::cout << ((k.second < 0) ? "YES" : "NO") << std::endl;
  }
}

}  // namespace Task130

#endif  // _TASK_83_HPP_