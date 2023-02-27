#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    // int n = word1.size(), m = word2.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // for (int i = 1; i <= m; ++i) {
    //   dp[0][i] = i;
    // }
    // for (int i = 1; i <= n; ++i) {
    //   dp[i][0] = i;
    // }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= m; ++j) {
    //     if (word1[i - 1] == word2[j - 1]) {
    //       dp[i][j] = dp[i - 1][j - 1];
    //     } else {
    //       dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
    //     }
    //   }
    // }
    // return dp[n][m];
    int m = word1.size(), n = word2.size(), pre = 0;
    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= m; ++i) {
      pre = dp[0];
      dp[0] = i;
      for (int j = 1; j <= n; ++j) {
        int temp = dp[j];
        if (word1[i - 1] == word2[j - 1]) {
          dp[j] = pre;
        } else {
          dp[j] = min({dp[j - 1], dp[j], pre}) + 1;
        }
        pre = temp;
      }
    }
    return dp[n];
  }
};