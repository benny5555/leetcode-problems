#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int dp[105][105]{};
    for (int i = cuts.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < cuts.size(); ++j) {
        for (int k = i + 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j],
                         cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
        }
      }
    }
    return dp[0][cuts.size() - 1];
  }
};