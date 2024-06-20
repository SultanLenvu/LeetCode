#include <set>
#include <string>
#include <vector>

#include "dfs.hpp"

int main() {
  std::vector<std::multiset<int>> Graph;
  std::set<int> Component;
  initGraph(Graph);

  dfs(Graph, Component);

  printResult(Component);
  return 0;
}
