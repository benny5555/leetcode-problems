#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> stk;
    for (int i = 0, j = 0; j < n; ++j) {
      while (stk.empty() || stk.top() != popped[j]) {
        if (i == n) return false;
        stk.push(pushed[i]);
        ++i;
      }
      stk.pop();
    }
    return true;
  }
};