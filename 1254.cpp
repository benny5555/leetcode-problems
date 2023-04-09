#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};
  int m, n;
  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y]) {
      return 0;
    }
    grid[x][y] = 1;
    int ans = 1;
    for (int i = 0; i < 4; ++i) {
      ans += dfs(grid, x + dir[i][0], y + dir[i][1]);
    }
    return ans;
  }

 public:
  int closedIsland(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          dfs(grid, i, j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += dfs(grid, i, j) > 0;
      }
    }
    return ans;
  }
};