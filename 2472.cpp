#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool pal[2005][2005]{};
  // dp[i] means maximum number of non-overlapping palindrome substrings from
  // [0, i).
  int dp[2005]{};

  int maxPalindromes(string s, int k) {
    for (int len = 0; len <= k; ++len) {
      for (int i = 0, j = i + len; j < s.size(); ++i, ++j) {
        pal[i][j] = (len < 2 ? true : pal[i + 1][j - 1]) && (s[i] == s[j]);
      }
    }
    for (int j = k; j <= s.size(); ++j) {
      for (int i = 1; i + k - 1 <= j; ++i) {
        if (pal[i - 1][j - 1]) {
          dp[j] = max(dp[j], 1 + dp[i - 1]);
        }
      }
      dp[j] = max(dp[j], dp[j - 1]);
    }
    return dp[s.size()];
  }
};