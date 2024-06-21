#include "task8.hpp"

#include <iostream>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

void Task8::initGraph(std::vector<std::unordered_multiset<int>>& graph) {
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

void Task8::printResult(
    const std::vector<std::unordered_set<int>>& components) {
  std::cout << components.size() << std::endl;

  for (const auto& c : components) {
    std::cout << c.size() << std::endl;
    for (const int& i : c) {
      std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
  }
}

void Task8::searchComponents(
    const std::vector<std::unordered_multiset<int>>& graph,
    std::vector<std::unordered_set<int>>& components) {
  std::unordered_set<int> visited;
  std::unordered_set<int> not_visited;

  for (int i = 0, s = graph.size(); i < s; ++i) {
    not_visited.insert(i);
  }

  while (not_visited.size() != 0) {
    std::unordered_set<int> component;

    searchComponent(graph, *not_visited.cbegin(), component);

    for (auto i : component) {
      visited.insert(i);
      not_visited.erase(i);
    }

    components.emplace_back(std::move(component));
  }
}

void Task8::searchComponent(
    const std::vector<std::unordered_multiset<int>>& graph, int vertex,
    std::unordered_set<int>& component) {
  component.insert(vertex);

  std::stack<int> stack;
  stack.push(vertex);
  component.insert(vertex);

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
