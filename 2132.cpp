#include <bits/stdc++.h>
using namespace std;
struct Presum2d {
  vector<vector<int>> presum2d;
  Presum2d() {}
  Presum2d(vector<vector<int>>& arr) { twodpresum(arr); }
  void twodpresum(vector<vector<int>>& arr) {
    int m = arr.size(), n = arr[0].size();
    presum2d.assign(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        presum2d[i][j] = arr[i - 1][j - 1] + presum2d[i][j - 1] +
                         presum2d[i - 1][j] - presum2d[i - 1][j - 1];
      }
    }
  }
  int sum2d(int x1, int y1, int x2, int y2) {
    return presum2d[x2 + 1][y2 + 1] + presum2d[x1][y1] - presum2d[x1][y2 + 1] -
           presum2d[x2 + 1][y1];
  }
};
class Solution {
 public:
  bool possibleToStamp(vector<vector<int>>& grid, int stampHeight,
                       int stampWidth) {
    int m = grid.size(), n = grid[0].size();
    Presum2d pre1(grid);
    vector<vector<int>> stamp(m, vector<int>(n));
    for (int i = stampHeight - 1; i < m; ++i) {
      for (int j = stampWidth - 1; j < n; ++j) {
        stamp[i][j] =
            pre1.sum2d(i - stampHeight + 1, j - stampWidth + 1, i, j) == 0;
      }
    }
    Presum2d pre2(stamp);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0 &&
            pre2.sum2d(i, j, min(i + stampHeight - 1, m - 1),
                       min(n - 1, j + stampWidth - 1)) == 0) {
          return false;
        }
      }
    }
    return true;
  }
};