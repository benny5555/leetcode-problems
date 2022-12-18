#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int ans = INT_MIN, n = nums.size(),
        target = accumulate(nums.begin(), nums.end(), -x);
    if (target == 0) return n;
    unordered_map<int, int> m{{0, -1}};
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (m.count(sum - target)) {
        ans = max(ans, i - m[sum - target]);
      }
      m[sum] = i;
    }
    return ans == INT_MIN ? -1 : n - ans;
  }
};