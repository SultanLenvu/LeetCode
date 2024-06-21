#ifndef _TASK_17_HPP_
#define _TASK_17_HPP_

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Task17 {
 public:
  static void init(std::unordered_map<std::string, int>& input);
  static void printResult(bool ok);
  static bool solve(std::unordered_map<std::string, int>& input);
};

#endif  // _TASK_17_HPP_