#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSwaps(string s) {
    int wrong = 0;
    stack<char> stk;
    for (auto c : s) {
      if (c == '[')
        stk.push(c);
      else {
        if (stk.empty())
          ++wrong;
        else
          stk.pop();
      }
    }
    return (wrong + 1) / 2;
  }
};