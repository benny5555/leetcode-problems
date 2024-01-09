#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int x, y, step;
  };
  int dir[8][2]{0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
      return -1;
    }
    if (n == 1) {
      return 1;
    }
    queue<node> que;
    que.push({0, 0, 1});
    grid[0][0] = 1;
    while (que.size()) {
      auto [x, y, step] = que.front();
      que.pop();
      for (int i = 0; i < 8; ++i) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n || grid[xx][yy]) continue;
        if (xx == n - 1 && yy == n - 1) {
          return step + 1;
        }
        que.push({xx, yy, step + 1});
        grid[xx][yy] = 1;
      }
    }
    return -1;
  }
};