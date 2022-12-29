#include <bits/stdc++.h>
using namespace std;
class Solution {
  using ll = long long;
#define v vector
  int n, m, dp[105][105][105]{};

 public:
  long long minimumTotalDistance(vector<int>& robot,
                                 vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    v<v<v<ll>>> dp(robot.size(),
                   v<v<ll>>(factory.size(), v<ll>(robot.size(), LLONG_MAX)));
    return dfs(0, 0, 0, robot, factory, dp);
  }
  ll dfs(int i, int j, int k, v<int>& robot, v<v<int>>& factory,
         v<v<v<ll>>>& dp) {
    if (i == robot.size()) return 0;
    if (j == factory.size()) return LLONG_MAX / 2;
    if (dp[i][j][k] != LLONG_MAX) return dp[i][j][k];
    return dp[i][j][k] = min(dfs(i, j + 1, 0, robot, factory, dp),
                             factory[j][1] > k
                                 ? dfs(i + 1, j, k + 1, robot, factory, dp) +
                                       abs(factory[j][0] - robot[i])
                                 : LLONG_MAX / 2);
  }
};