#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    int target = sum >> 1;
    vector<bool> dp(target + 1);
    dp[0] = true;
    for (auto num : nums) {
      for (int j = target; j >= num; --j) {
        if (dp[j - num]) dp[j] = dp[j - num];
      }
    }
    return dp[target];
  }
};