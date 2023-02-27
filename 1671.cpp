#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size(), ans = n;
    vector<int> lis(n), lds(n), v;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      auto it = lower_bound(v.begin(), v.end(), x);
      lis[i] = it - v.begin();
      if (it != v.end()) {
        *it = x;
      } else {
        v.push_back(x);
      }
    }
    v.clear();
    for (int i = n - 1; i >= 0; --i) {
      int x = nums[i];
      auto it = lower_bound(v.begin(), v.end(), x);
      lds[i] = it - v.begin();
      if (it != v.end()) {
        *it = x;
      } else {
        v.push_back(x);
      }
    }
    for (int i = 1; i < n; ++i) {
      if (lis[i] && lds[i]) {
        ans = min(ans, n - lis[i] - lds[i] - 1);
      }
    }
    return ans;
  }
};