#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    string ans;
    stack<int> stk;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '(')
        stk.push(i);
      else if (s[i] == ')') {
        if (stk.empty())
          s[i] = '!';
        else
          stk.pop();
      }
    }
    while (stk.size()) {
      s[stk.top()] = '!';
      stk.pop();
    }
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '!') continue;
      ans.push_back(s[i]);
    }
    return ans;
  }
};