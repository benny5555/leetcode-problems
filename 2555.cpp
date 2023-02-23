#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximizeWin(vector<int>& prizePositions, int k) {
    int n = prizePositions.size(), ans = 0;
    vector<int> dp(n + 1);
    for (int left = 0, right = 0; right < n; ++right) {
      while (prizePositions[right] - prizePositions[left] > k) {
        ++left;
      }
      dp[right + 1] = max(dp[right], right - left + 1);
      ans = max(ans, right - left + 1 + dp[left]);
    }
    return ans;
  }
};