#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int n = floor.size();
    vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= numCarpets; ++j) {
        int skip = dp[i - 1][j] + floor[i - 1] - '0',
            pick = j ? dp[max(i - carpetLen, 0)][j - 1] : INT_MAX;
        dp[i][j] = min(skip, pick);
      }
    }
    return dp[n][numCarpets];
  }
};