#include "task74.hpp"

int main() {
  std::unordered_map<std::string, int> Input;

  Task74::init(Input);

  Task74::printResult(Task74::solve(Input));

  return 0;
}
