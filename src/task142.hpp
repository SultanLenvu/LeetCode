#ifndef _TASK_142_HPP_
#define _TASK_142_HPP_

#include <functional>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Task142 {

void initTokens(std::vector<std::string>& tokens) {
  std::string expression;
  std::getline(std::cin, expression);
  std::stringstream ss(expression);

  std::string token;
  while (std::getline(ss, token, ' ')) {
    tokens.emplace_back(std::move(token));
  }
}

void solve() {
  std::vector<std::string> Tokens;
  initTokens(Tokens);

  std::unordered_map<std::string, std::function<int(int, int)>> Operations;
  Operations["+"] = [](int op1, int op2) { return op1 + op2; };
  Operations["-"] = [](int op1, int op2) { return op1 - op2; };
  Operations["*"] = [](int op1, int op2) { return op1 * op2; };

  std::stack<int> calc;
  for (const auto& t : Tokens) {
    if (Operations.count(t) > 0) {
      int op2 = calc.top();
      calc.pop();
      int op1 = calc.top();
      calc.pop();
      calc.push(Operations[t](op1, op2));
    } else {
      calc.push(std::stoi(t));
    }
  }

  std::cout << calc.top();
}

};  // namespace Task142

#endif  // _TASK_142_HPP_