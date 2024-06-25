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

void dfs(const std::vector<std::unordered_set<int>>& graph, int start,
         std::vector<VertexColor>& colors, std::vector<int>& sequence) {
  std::stack<int> need2visit;
  need2visit.push(start);
  std::vector<int> parents(graph.size(), -1);

  while (!need2visit.empty()) {
    int current = need2visit.top();

    if (colors[current] == VertexColor::Grey) {
      colors[current] = VertexColor::Black;
      need2visit.pop();
      sequence.pop_back();
      continue;
    }
    sequence.push_back(current);
    colors[current] = VertexColor::Grey;
    // std::cout << "  grey " << current << std::endl;

    for (int neighbor : graph[current]) {
      if (colors[neighbor] == VertexColor::White) {
        parents[neighbor] = current;
        need2visit.push(neighbor);
        // std::cout << "stack " << neighbor << std::endl;
      } else if ((colors[neighbor] == VertexColor::Grey) &&
                 (parents[current] != neighbor) && (parents[current] != -1)) {
        sequence.push_back(neighbor);
        std::cout << "      grey neighbor " << neighbor << " | sequence ";
        for (auto i : sequence) {
          std::cout << i << " ";
        }
        std::cout << std::endl;
        return;
      }
    }
  }
  sequence.clear();
}

void printCycle(const std::unordered_set<int>& cycle) {
  if (cycle.size() == 0) {
    std::cout << "NO";
    return;
  }

  std::cout << "YES" << std::endl;
  std::cout << cycle.size() << std::endl;
  for (auto i : cycle) {
    std::cout << i << " ";
  }
}

void searchCycle(const std::vector<int>& sequence,
                 std::unordered_set<int>& cycle) {
  for (int i = sequence.size() - 1; i >= 0; --i) {
    if (cycle.count(sequence[i]) > 0) {
      return;
    }
    cycle.insert(sequence[i]);
  }
  cycle.clear();
}

void testInit(std::vector<std::unordered_set<int>>& graph) {
  graph.resize(7);

  graph[0].insert(1);
  graph[0].insert(6);
  graph[0].insert(4);

  graph[1].insert(0);
  graph[1].insert(2);

  graph[2].insert(3);
  graph[2].insert(1);
  graph[2].insert(4);

  graph[3].insert(6);
  graph[3].insert(5);
  graph[3].insert(2);

  graph[4].insert(0);
  graph[4].insert(2);
  graph[4].insert(5);

  graph[5].insert(3);
  graph[5].insert(4);

  graph[6].insert(3);
  graph[6].insert(0);
}

void testInit1(std::vector<std::unordered_set<int>>& graph) {
  graph.reserve(6);

  graph.push_back({1, 2});
  graph.push_back({0, 3});
  graph.push_back({0, 4, 5, 3});
  graph.push_back({1, 2});
  graph.push_back({2, 5});
  graph.push_back({2, 4});
}

void solve() {
  std::vector<std::unordered_set<int>> graph;
  // initGraph(graph);
  testInit1(graph);

  std::vector<VertexColor> colors(graph.size(), VertexColor::White);
  std::vector<int> sequence;
  std::unordered_set<int> cycle;

  for (int i = 0; i < graph.size(); ++i) {
    if (colors[i] == VertexColor::White) {
      dfs(graph, i, colors, sequence);
    }
    if (sequence.size() > 0) {
      searchCycle(sequence, cycle);
      break;
    }
  }
  printCycle(cycle);
}

};  // namespace Task10

#endif  // _TASK_10_HPP_