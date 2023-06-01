#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int n = s1.size();
    if (s1 == s2) return true;
    // s1 starting from i and s2 starting from j, within len, can they be
    // Scrambled strings?
    bool dp[30][30][31]{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s1[i] == s2[j]) {
          dp[i][j][1] = 1;
        }
      }
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i + len <= n; ++i) {
        for (int j = 0; j + len <= n; ++j) {
          for (int k = 1; k < len; ++k) {
            bool a = dp[i][j][k] && dp[i + k][j + k][len - k];
            bool b = dp[i][j + len - k][k] && dp[i + k][j][len - k];
            if (a || b) {
              dp[i][j][len] = true;
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};