#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; --i) {
      while (stk.size() && temperatures[stk.top()] <= temperatures[i]) {
        stk.pop();
      }
      if (stk.size()) {
        ans[i] = stk.top() - i;
      } else {
        ans[i] = 0;
      }
      stk.push(i);
    }
    return ans;
  }
};