#ifndef _TASK_74_HPP_
#define _TASK_74_HPP_

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Task74 {
 public:
  static void init(std::unordered_map<std::string, int>& input);
  static void printResult(bool ok);
  static bool solve(std::unordered_map<std::string, int>& input);
};

#endif  // _TASK_74_HPP_