#ifndef _TASK_9_HPP_
#define _TASK_9_HPP_

#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Task9 {

void solve() {
  std::vector<std::unordered_set<int>> graph;
  int N = 0, M = 0;

  std::cin >> N >> M;
  graph.resize(N);

  int t1 = 0, t2 = 0;
  for (int i = 0; i < M; i++) {
    std::cin >> t1 >> t2;
    graph[t1 - 1].insert(t2 - 1);
    graph[t2 - 1].insert(t1 - 1);
  }

  std::vector<int> colors(N, 0);
  std::queue<int> q;

  for (int start = 0; start < N; ++start) {
    if (colors[start] == 0) {
      q.push(start);
      colors[start] = 1;

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
          if (colors[neighbor] == 0) {
            colors[neighbor] = 3 - colors[node];
            q.push(neighbor);
          } else if (colors[neighbor] == colors[node]) {
            std::cout << "NO";
            return;
          }
        }
      }
    }
  }
  std::cout << "YES";
}

};  // namespace Task9

#endif  // _TASK_9_HPP_