#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int m, n, k, mod;
  int numberOfPaths(vector<vector<int>>& grid, int K) {
    m = grid.size(), n = grid[0].size(), mod = 1e9 + 7, k = K;
    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(k, -1)));
    return dfs(0, 0, 0, grid, dp);
  }
  int dfs(int i, int j, int sum, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
    if (i == m || j == n) return 0;
    if (i == m - 1 && j == n - 1) return ((sum + grid[i][j]) % k) == 0;
    if (dp[i][j][sum] != -1) return dp[i][j][sum];
    return dp[i][j][sum] = (dfs(i + 1, j, (sum + grid[i][j]) % k, grid, dp) +
                            dfs(i, j + 1, (sum + grid[i][j]) % k, grid, dp)) %
                           mod;
  }
  // int numberOfPaths(vector<vector<int>>& grid, int K) {
  //   m = grid.size(), n = grid[0].size(), mod = 1e9 + 7, k = K;
  //   vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,
  //   vector<int>(k))); dp[0][0][grid[0][0] % k] = 1; for (int i = 0; i < m;
  //   ++i) {
  //     for (int j = 0; j < n; ++j) {
  //       for (int s = 0; s < k; ++s) {
  //         int tmp = (s + grid[i][j]) % k;
  //         if (i) dp[i][j][tmp] += dp[i - 1][j][s];
  //         if (j) dp[i][j][tmp] += dp[i][j - 1][s];
  //         dp[i][j][tmp] %= mod;
  //       }
  //     }
  //   }
  //   return dp[m - 1][n - 1][0];
  // }
};
