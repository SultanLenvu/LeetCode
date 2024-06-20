#include <set>
#include <vector>

void initGraph(std::vector<std::multiset<int>>& graph);
void printResult(const std::set<int>& component);
void dfs(const std::vector<std::multiset<int>>& graph,
         std::set<int>& component);