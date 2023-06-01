#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};
  int m, n;
  struct node {
    int x, y, step;
  };
  queue<node> que;
  void dfs(vector<vector<int>>& grid, int x, int y) {
    que.push({x, y, 0});
    grid[x][y] = 2;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dir[i][0], yy = y + dir[i][1];
      if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
      if (grid[xx][yy] == 1) {
        dfs(grid, xx, yy);
      }
    }
  }

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    int flag = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          dfs(grid, i, j);
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    while (que.size()) {
      auto now = que.front();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int x = now.x + dir[i][0], y = now.y + dir[i][1];
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 2) continue;
        if (grid[x][y] == 1) {
          return now.step;
        } else {
          grid[x][y] = 2;
          que.push({x, y, now.step + 1});
        }
      }
    }
    return -1;
  }
};