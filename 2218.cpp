#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    int dp[1001][2005]{};
    function<int(int, int)> dfs = [&](int i, int k) {
      if (i == n || k == 0) return 0;
      if (dp[i][k]) return dp[i][k];
      int ans = dfs(i + 1, k), mmax = 0;
      int m = piles[i].size();
      for (int j = 0; j < k && j < m; ++j) {
        mmax += piles[i][j];
        ans = max(ans, dfs(i + 1, k - j - 1) + mmax);
      }
      return dp[i][k] = ans;
    };
    return dfs(0, k);
  }
};