#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0),
        diff = sum - target;
    if (diff < 0 || diff & 1) {
      return 0;
    }
    int neg = diff >> 1;
    vector<int> dp(neg + 1);
    dp[0] = 1;
    for (int num : nums) {
      for (int j = neg; j >= 1; --j) {
        dp[j] = dp[j - 1];
        if (j >= num) {
          dp[j] += dp[j - num];
        }
      }
    }
    return dp[neg];
  }
};