#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0) return 1.0;
    vector<double> dp(k + maxPts);
    for (int i = k; i <= n && i < k + maxPts; ++i) {
      dp[i] = 1.0;
    }
    if (n >= k - 1 + maxPts) {
      dp[k - 1] = 1.0;
    } else {
      dp[k - 1] = (double)(n - k + 1) / maxPts;
    }
    for (int i = k - 2; i >= 0; --i) {
      dp[i] = dp[i + 1] + (dp[i + 1] - dp[i + 1 + maxPts]) / maxPts;
    }
    return dp[0];
  }
};