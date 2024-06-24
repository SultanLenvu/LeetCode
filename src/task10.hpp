#ifndef _TASK_10_HPP_
#define _TASK_10_HPP_

#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Task10 {

void solve() {
  std::vector<std::unordered_set<int>> graph;
  int N = 0, M = 0;

  std::cin >> N >> M;
  graph.resize(N);

  int t1 = 0, t2 = 0;
  for (int i = 0; i < M; i++) {
    std::cin >> t1 >> t2;
    graph[t1 - 1].insert(t2 - 1);
  }

  std::vector<bool> visited;
  visited[0] = true;
  std::stack<int> need2visit;
  need2visit.push(0);

  while (!need2visit.empty()) {
    int current = need2visit.top();
    need2visit.pop();

    for (int neighbor : graph[current]) {
      if (visited[neighbor]) {
        need2visit.push(neighbor);
      }
    }

    visited[current] = true;
  }
}

};  // namespace Task10

#endif  // _TASK_10_HPP_