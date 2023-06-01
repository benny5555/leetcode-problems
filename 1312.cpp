#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    // dp[i][j] means the length of longest common sequence between i first
    // letters in s1 and j first letters in s2.

    int dp[505][505]{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = s[i] == s[n - 1 - j]
                               ? dp[i][j] + 1
                               : max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return n - dp[n][n];
  }
};