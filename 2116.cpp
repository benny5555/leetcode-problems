#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    auto check = [&](char c) {
      bool normal = c == '(' ? true : false;
      int flex = 0, diff = 0, start = normal ? 0 : n - 1, dir = normal ? 1 : -1;
      // if there is not enough (/) before)/after( directly jump out.
      for (int i = start; i < n && i >= 0 && flex >= -diff; i += dir) {
        if (locked[i] == '1') {
          diff += c == s[i] ? 1 : -1;
        } else {
          ++flex;
        }
      }
      return flex >= abs(diff);
    };
    return n % 2 == 0 && check('(') && check(')');
  }
};