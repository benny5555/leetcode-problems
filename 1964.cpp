#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> dp;
    int n = obstacles.size();
    for (int i = 0; i < n; ++i) {
      if (dp.empty() || dp.back() <= obstacles[i]) {
        dp.push_back(obstacles[i]);
        obstacles[i] = dp.size();
      } else {
        int ind = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
        dp[ind] = obstacles[i];
        obstacles[i] = ++ind;
      }
    }
    return obstacles;
  }
};