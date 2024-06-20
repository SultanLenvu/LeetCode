#ifndef _TASK_8_HPP_
#define _TASK_8_HPP_

#include <set>
#include <vector>

class Task8 {
 public:
  static void initGraph(std::vector<std::multiset<int>>& graph);
  static void printResult(const std::vector<std::set<int>>& components);
  static void searchComponents(const std::vector<std::multiset<int>>& graph,
                  std::vector<std::set<int>>& components);
};

#endif  // _TASK_8_HPP_