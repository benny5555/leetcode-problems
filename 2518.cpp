#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countPartitions(vector<int>& nums, int k) {
    long sum = 0, total = 1, mod = 1e9 + 7;
    vector<long> dp(k + 1);
    dp[0] = 1;
    for (auto num : nums) {
      sum = (sum + num) % mod;
      total = (total * 2) % mod;
      for (int j = k - 1; j >= num; --j) {
        dp[j] = (dp[j] + dp[j - num]) % mod;
      }
    }
    if (sum < 2 * k) return 0;
    long smaller_than_k = 0;
    for (int i = 0; i < k; ++i) {
      smaller_than_k = (smaller_than_k + dp[i]) % mod;
    }
    return (total - 2 * smaller_than_k + mod) % mod;
  }
};