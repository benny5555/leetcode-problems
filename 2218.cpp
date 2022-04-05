#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    vector<vector<int>> memo(n, vector<int>(k + 1));
    function<int(int, int)> dfs = [&](int i, int k) {
      if (i == n || k == 0) return 0;
      if (memo[i][k]) return memo[i][k];
      int ans = dfs(i + 1, k), pile = 0;
      for (int j = 0; j < piles[i].size() && j < k; ++j) {
        pile += piles[i][j];
        ans = max(ans, dfs(i + 1, k - j - 1) + pile);
      }
      return memo[i][k] = ans;
    };
    return dfs(0, k);
  }
};