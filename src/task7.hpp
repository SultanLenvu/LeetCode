#ifndef _TASK_7_HPP_
#define _TASK_7_HPP_

#include <set>
#include <vector>

class Task7 {
 public:
  static void initGraph(std::vector<std::multiset<int>>& graph);
  static void printResult(const std::set<int>& component);
  static void dfs(const std::vector<std::multiset<int>>& graph,
                  std::set<int>& component);
};

#endif  // _TASK_7_HPP_