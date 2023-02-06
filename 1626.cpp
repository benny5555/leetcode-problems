#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int ans = 0, n = ages.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.push_back({ages[i], scores[i]});
    }
    sort(v.rbegin(), v.rend());
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      auto& [age, score] = v[i];
      dp[i] = score;
      for (int j = 0; j < i; ++j) {
        if (v[j].second >= score) {
          dp[i] = max(dp[i], dp[j] + score);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};