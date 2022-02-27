#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size(), pre;
    vector<int> dp(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int temp = dp[j];
        if (!i || !j || matrix[i][j] == '0') {
          dp[j] = matrix[i][j] - '0';
        } else {
          dp[j] = min({pre, dp[j], dp[j - 1]}) + 1;
        }
        ans = max(ans, dp[j]);
        pre = temp;
      }
    }
    return ans * ans;
  }
};