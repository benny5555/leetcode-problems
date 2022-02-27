#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    vector<long long> dp(n + 1);
    vector<vector<pair<int, int>>> graph(n);
    for (auto &ride : rides) {
      graph[ride[0]].push_back({ride[1], ride[1] - ride[0] + ride[2]});
    }
    for (int i = n - 1; i >= 1; --i) {
      for (auto &next : graph[i]) {
        int e = next.first, v = next.second;
        dp[i] = max(dp[i], dp[e] + v);
      }
      dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[1];
  }
};