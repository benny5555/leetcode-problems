#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                        int numLaps) {
    int n = tires.size(), len = 0;
    vector<long> dp(numLaps + 1, LONG_MAX), best(numLaps, LONG_MAX);
    for (int i = 0; i < n; ++i) {
      long f = tires[i][0], r = tires[i][1], factor = 1, sum = changeTime;
      for (int j = 0; j < numLaps; ++j) {
        long temp = f * factor;
        if (temp > f + changeTime) break;
        sum += temp;
        factor *= r;
        best[j] = min(best[j], sum);
        len = max(len, j + 1);
      }
    }
    dp[0] = 0;
    for (int i = 0; i < numLaps; ++i) {
      for (int j = 0; j < len && i - j >= 0; ++j) {
        dp[i + 1] = min(dp[i + 1], dp[i - j] + best[j]);
      }
    }
    return dp[numLaps] - changeTime;
  }
};