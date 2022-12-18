#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string a, string b) {
    int m = a.size(), n = b.size();
    int dp[1001][1001]{};
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1
                                        : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
};