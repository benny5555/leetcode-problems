#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    int ans = 0, m = grid.size(), n = grid[0].size();
    for (auto& row : grid) {
      sort(row.begin(), row.end());
    }
    for (int j = 0; j < n; ++j) {
      int temp = 0;
      for (int i = 0; i < m; ++i) {
        temp = max(temp, grid[i][j]);
      }
      ans += temp;
    }
    return ans;
  }
};
