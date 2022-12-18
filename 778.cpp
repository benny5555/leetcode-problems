#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int x, y, time;
    bool operator<(const node& b) const { return time > b.time; }
  };

  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};

 public:
  int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    priority_queue<node> pq;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
    pq.push({0, 0, grid[0][0]});
    vis[0][0] = true;
    while (pq.size()) {
      auto now = pq.top();
      ans = max(ans, grid[now.x][now.y]);
      pq.pop();
      for (int i = 0; i < 4; ++i) {
        int x = now.x + dir[i][0];
        int y = now.y + dir[i][1];
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
            vis[x][y])
          continue;
        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
          ans = max(ans, grid[x][y]);
          return ans;
        }
        pq.push({x, y, grid[x][y]});
        vis[x][y] = true;
      }
    }
    return ans;
  }
};
