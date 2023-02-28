#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int trap(vector<int>& height) {
    stack<int> stk;
    int ans = 0, n = height.size();
    for (int i = 0; i < n; ++i) {
      while (stk.size() && height[i] > height[stk.top()]) {
        int high = height[stk.top()];
        stk.pop();
        if (stk.empty()) {
          break;
        }
        ans += (min(height[i], height[stk.top()]) - high) * (i - stk.top() - 1);
      }
      stk.push(i);
    }
    return ans;
  }
};