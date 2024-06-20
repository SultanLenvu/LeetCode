#include "dfs.hpp"

#include <iostream>
#include <set>
#include <stack>
#include <vector>

void initGraph(std::vector<std::multiset<int>>& graph) {
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

void printResult(const std::set<int>& component) {
  std::cout << component.size() << std::endl;
  for (const int& i : component) {
    std::cout << i + 1 << " ";
  }
}

void dfs(const std::vector<std::multiset<int>>& graph,
         std::set<int>& component) {
  component.insert(0);

  // "Лобовое" решение
  // for (int i = 0, s = graph.size(); i < s; ++i) {
  //   if (component.count(i) == 1) {
  //     for (const auto& j : graph[i]) {
  //       component.insert(j);
  //     }
  //   }
  // }

  std::stack<int> stack;
  stack.push(0);
  component.insert(0);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();

    for (int neighbor : graph[current]) {
      if (component.count(neighbor) == 0) {
        stack.push(neighbor);
        component.insert(neighbor);
      }
    }
  }
}