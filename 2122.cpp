#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) {
      int k2 = nums[i] - nums[0];
      if (k2 == 0 || k2 & 1) continue;
      int ind = 0, left = 0, right = i;
      vector<int> ans(n / 2), vis(n);
      for (int j = 0; j < n / 2; ++j) {
        while (left < n && vis[left]) ++left;
        while (right < n && nums[right] - nums[left] != k2) ++right;
        if (right == n) break;
        ++vis[right];
        ans[ind++] = nums[left] + k2 / 2;
        ++left, ++right;
      }
      if (ind == n / 2) return ans;
    }
    return {};
  }
};