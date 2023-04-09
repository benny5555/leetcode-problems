#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};
  int m, n;
  void dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) return;
    grid[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dir[i][0];
      int yy = y + dir[i][1];
      dfs(grid, xx, yy);
    }
  }

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          dfs(grid, i, j);
        }
      }
    }
    return accumulate(grid.begin(), grid.end(), 0, [](int s, vector<int>& v) {
      return s + accumulate(v.begin(), v.end(), 0);
    });
  }
};