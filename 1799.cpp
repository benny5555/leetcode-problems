#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
class Solution {
  int dp[8][16384]{};

 public:
  int maxScore(vector<int>& nums, int i = 1, int mask = 0) {
    if (i > nums.size() / 2) {
      return 0;
    }
    if (!dp[i][mask]) {
      for (int j = 0; j < nums.size(); ++j) {
        for (int k = j + 1; k < nums.size(); ++k) {
          int new_mask = (1 << j) | (1 << k);
          if ((mask & new_mask) == 0) {
            dp[i][mask] =
                max(dp[i][mask], i * gcd(nums[j], nums[k]) +
                                     maxScore(nums, i + 1, mask | new_mask));
          }
        }
      }
    }
    return dp[i][mask];
  }
};