#include <bits/stdc++.h>
using namespace std;
class Solution {
  // dp[i,m] = maximum stone the current player can get from piles[i:] with M=m
  int dp[105][105]{};

 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    for (int i = n - 2; i >= 0; --i) {
      piles[i] += piles[i + 1];
    }
    function<int(int, int)> dfs = [&](int i, int m) -> int {
      if (i + m * 2 >= n) {
        return piles[i];
      }
      if (dp[i][m]) return dp[i][m];
      int mmin = INT_MAX;
      for (int x = 1; x <= m * 2; ++x) {
        mmin = min(mmin, dfs(i + x, max(m, x)));
      }
      return dp[i][m] = piles[i] - mmin;
    };
    return dfs(0, 1);
  }
};