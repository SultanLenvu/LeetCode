#ifndef _TASK_8_HPP_
#define _TASK_8_HPP_

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Task8 {
 public:
  static void initGraph(std::vector<std::unordered_multiset<int>>& graph);
  static void printResult(
      const std::vector<std::unordered_set<int>>& components);
  static void searchComponents(
      const std::vector<std::unordered_multiset<int>>& graph,
      std::vector<std::unordered_set<int>>& components);

 private:
  static void searchComponent(
      const std::vector<std::unordered_multiset<int>>& graph, int vertex,
      std::unordered_set<int>& component);
};

#endif  // _TASK_8_HPP_