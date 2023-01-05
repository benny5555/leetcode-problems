#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    sort(points.begin(), points.end(),
         [&](const auto& a, const auto& b) { return a[1] < b[1]; });
    int end = points[0][1], ans = 1, n = points.size();
    for (int i = 1; i < n; ++i) {
      if (end >= points[i][0]) {
        continue;
      }
      ++ans;
      end = points[i][1];
    }
    return ans;
  }
};