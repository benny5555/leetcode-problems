#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int dp[71][70 * 70 + 5]{};
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    // int m = mat.size(), n = mat[0].size();
    // // dp[i][j] means from the previous i rows whether it is possible to have
    // a
    // // sum of j.
    // for (auto num : mat[0]) {
    //   dp[0][num] = true;
    // }
    // for (int i = 1; i < m; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     int num = mat[i][j];
    //     for (int k = num; k < 4901; ++k) {
    //       if (dp[i - 1][k - num]) dp[i][k] = true;
    //     }
    //   }
    // }
    // int ans = INT_MAX;
    // for (int i = 0; i <= 4900; ++i) {
    //   if (dp[m - 1][i]) {
    //     ans = min(ans, abs(target - i));
    //   }
    // }
    // return ans;
    int m = mat.size(), n = mat[0].size();
    bitset<4905>* dp = new bitset<4905>[m];
    dp[0] = 0;
    for (auto num : mat[0]) {
      dp[0][num] = 1;
    }
    for (int i = 1; i < m; ++i) {
      dp[i] = 0;
      for (int j = 0; j < n; ++j) {
        dp[i] |= dp[i - 1] << mat[i][j];
      }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= 4900; ++i) {
      if (dp[m - 1][i]) {
        ans = min(ans, abs(target - i));
      }
    }
    delete[] dp;
    return ans;
  }
};