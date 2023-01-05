#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    string ans;
    // dp[i] means when the total cost is i, the maximum digits that we can
    // achieve.
    vector<int> dp(target + 1, INT_MIN / 2);
    dp[0] = 0;
    for (int num : cost) {
      for (int j = num; j <= target; ++j) {
        dp[j] = max(dp[j], dp[j - num] + 1);
      }
    }
    if (dp[target] <= 0) {
      return "0";
    }
    for (int i = 8, j = target; i >= 0; --i) {
      for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c) {
        ans += '1' + i;
      }
    }
    return ans;
  }
};