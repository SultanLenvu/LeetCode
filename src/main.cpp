#include <set>
#include <string>
#include <vector>

#include "task8.hpp"

int main() {
  std::vector<std::multiset<int>> Graph;
  std::vector<std::set<int>> Components;
  Task8::initGraph(Graph);

  Task8::dfs(Graph, Components);

  Task8::printResult(Components);
  return 0;
}
