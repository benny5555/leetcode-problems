#include <bits/stdc++.h>
using namespace std;
#define v vector
class Solution {
  int mod = 1e9 + 7;
  int dfs(int m, int n, int k, int i, int j, v<v<v<int>>>& dp,
          v<v<int>>& pre_sum) {
    if (pre_sum[i][j] == 0) return 0;
    if (k == 0) return 1;
    if (dp[k][i][j] != -1) return dp[k][i][j];
    int ans = 0;
    for (int l = i + 1; l < m; ++l) {
      if (pre_sum[i][j] - pre_sum[l][j] > 0) {
        ans = (ans + dfs(m, n, k - 1, l, j, dp, pre_sum)) % mod;
      }
    }
    for (int nj = j + 1; nj < n; ++nj) {
      if (pre_sum[i][j] - pre_sum[i][nj] > 0) {
        ans = (ans + dfs(m, n, k - 1, i, nj, dp, pre_sum)) % mod;
      }
    }
    return dp[k][i][j] = ans;
  }

 public:
  int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    v<v<v<int>>> dp(k, v<v<int>>(m, v<int>(n, -1)));
    v<v<int>> pre_sum(m + 1, v<int>(n + 1));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        pre_sum[i][j] = pre_sum[i][j + 1] + pre_sum[i + 1][j] -
                        pre_sum[i + 1][j + 1] + (pizza[i][j] == 'A');
      }
    }
    return dfs(m, n, k - 1, 0, 0, dp, pre_sum);
  }
};