#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    // dp[i] means if we ignore before stonValue[i], the highest score that Alex
    // can win over the Bob.
    vector<int> dp(n, -1e9);
    for (int i = n - 1; i >= 0; --i) {
      for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
        take += stoneValue[i + k];
        dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
      }
    }
    if (dp[0] > 0) {
      return "Alice";
    }
    if (dp[0] < 0) {
      return "Bob";
    }
    return "Tie";
  }
};