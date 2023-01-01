#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    int mod = 1e9 + 7, ans = 0;
    // dp[i][j]: the count of schemes with i members and at least j profits.
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
    dp[0][0] = 1;
    for (int k = 0; k < group.size(); ++k) {
      auto g = group[k], p = profit[k];
      for (int i = n; i >= g; --i) {
        for (int j = minProfit; j >= 0; --j) {
          dp[i][j] = (dp[i][j] + dp[i - g][max(0, j - p)]) % mod;
        }
      }
    }
    for (int i = 0; i <= n; ++i) {
      ans = (ans + dp[i][minProfit]) % mod;
    }
    return ans;
  }
};