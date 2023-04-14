#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[1005][1005]{};
    for (int len = 1; len <= n; ++len) {
      for (int l = 0; l <= n - len; ++l) {
        int r = l + len - 1;
        if (len == 1) {
          dp[l][r] = 1;
        } else if (s[l] == s[r]) {
          dp[l][r] = 2 + dp[l + 1][r - 1];
        } else {
          dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};