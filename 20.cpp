#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for (auto c : s) {
      if (c == ']') {
        if (stk.empty() || stk.top() != '[') return false;
        stk.pop();
      } else if (c == '}') {
        if (stk.empty() || stk.top() != '{') return false;
        stk.pop();
      } else if (c == ')') {
        if (stk.empty() || stk.top() != '(') return false;
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    return stk.empty();
  }
};