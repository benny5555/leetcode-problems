#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (stk.size() && heights[stk.top()] <= heights[i]) {
        ++ans[stk.top()], stk.pop();
      }
      if (stk.size()) ++ans[stk.top()];
      stk.push(i);
    }
    return ans;
  }
};

int __IO = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();