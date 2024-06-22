#ifndef _TASK_7_HPP_
#define _TASK_7_HPP_

#include <iostream>
#include <set>
#include <stack>
#include <vector>


namespace Task7 {

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

};  // namespace Task7

#endif  // _TASK_7_HPP_