#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestAwesome(string s) {
    int state = 0, ans = 0;
    vector<int> dp(1 << 10, INT_MAX / 2);
    dp[0] = -1;
    for (int i = 0; s[i]; ++i) {
      state ^= 1 << (s[i] - '0');
      ans = max(ans, i - dp[state]);
      for (int j = 0; j < 10; ++j) {
        ans = max(ans, i - dp[state ^ (1 << j)]);
      }
      dp[state] = min(dp[state], i);
    }
    return ans;
  }
};