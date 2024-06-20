#include "task8.hpp"

#include <iostream>
#include <set>
#include <stack>
#include <vector>

void Task8::initGraph(std::vector<std::multiset<int>>& graph) {
  int N = 0, M = 0;

  std::cin >> N >> M;
  graph.resize(N);

  int t1 = 0, t2 = 0;
  for (int i = 0; i < M; i++) {
    std::cin >> t1 >> t2;
    graph[t1 - 1].insert(t2 - 1);
    graph[t2 - 1].insert(t1 - 1);
  }
}

void Task8::printResult(const std::vector<std::set<int>>& components) {
  std::cout << components.size() << std::endl;

  for (const auto& c : components) {
    std::cout << c.size() << std::endl;
    for (const int& i : c) {
      std::cout << i + 1 << " ";
    }
  }
}

void Task8::searchComponents(const std::vector<std::multiset<int>>& graph,
                             std::vector<std::set<int>>& components) {
  // component.insert(0);

  // std::stack<int> stack;
  // stack.push(0);
  // component.insert(0);

  // while (!stack.empty()) {
  //   int current = stack.top();
  //   stack.pop();

  //   for (int neighbor : graph[current]) {
  //     if (component.count(neighbor) == 0) {
  //       stack.push(neighbor);
  //       component.insert(neighbor);
  //     }
  //   }
  // }
}