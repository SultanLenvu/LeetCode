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

enum class VertexColor {
  White,
  Grey,
  Black,
};

void initGraph(std::vector<std::unordered_set<int>>& graph) {
  int N = 0;

  std::cin >> N;
  graph.resize(N);

  int t1 = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> t1;
      if (t1 == 1) {
        graph[i].insert(j);
      }
    }
  }
}

void searchCycle(const std::vector<std::unordered_set<int>>& graph, int start,
                 std::vector<VertexColor>& colors, std::vector<int>& cycle) {
  std::stack<int> need2visit;
  need2visit.push(start);
  colors[start] = VertexColor::Grey;

  while (!need2visit.empty()) {
    int current = need2visit.top();
    need2visit.pop();
    cycle.push_back(current);

    for (int neighbor : graph[current]) {
      if ((cycle.size() >= 2) && (*(cycle.end() - 2) == neighbor)) {
        continue;
      }
      if (colors[neighbor] == VertexColor::White) {
        need2visit.push(neighbor);
        colors[neighbor] = VertexColor::Grey;
      } else if (colors[neighbor] == VertexColor::Black) {
        continue;
      } else if (colors[neighbor] == VertexColor::Grey) {
        cycle.push_back(neighbor);
        return;
      }
    }
  }
  colors[start] = VertexColor::Black;
}

void printCycle(const std::vector<int>& cycle) {
  if (cycle.size() == 0) {
    std::cout << "NO";
    return;
  }

  std::cout << "YES" << std::endl;
  std::cout << cycle.size() << std::endl;
  for (auto i : cycle) {
    std::cout << i + 1 << " ";
  }
}

void solve() {
  std::vector<std::unordered_set<int>> graph;
  initGraph(graph);

  std::vector<VertexColor> colors(graph.size(), VertexColor::White);
  std::vector<int> cycle;

  for (int i = 0; i < graph.size(); ++i) {
    if (colors[i] == VertexColor::White) {
      searchCycle(graph, i, colors, cycle);
    }
    if (cycle.size() > 0) {
      break;
    }
  }

  printCycle(cycle);
}

};  // namespace Task10

#endif  // _TASK_10_HPP_