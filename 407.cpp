#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int x, y, height;
    bool operator<(const node& b) const { return height > b.height; }
  };
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};

 public:
  int trapRainWater(vector<vector<int>>& mmap) {
    bool vis[205][205]{};
    int m = mmap.size(), n = mmap[0].size();
    priority_queue<node> pq;
    for (int i = 0; i < m; ++i) {
      pq.push({i, 0, mmap[i][0]});
      pq.push({i, n - 1, mmap[i][n - 1]});
      vis[i][0] = vis[i][n - 1] = true;
    }
    for (int j = 1; j < n - 1; ++j) {
      pq.push({0, j, mmap[0][j]});
      pq.push({m - 1, j, mmap[m - 1][j]});
      vis[0][j] = vis[m - 1][j] = true;
    }
    int ans = 0;
    while (pq.size()) {
      auto now = pq.top();
      pq.pop();
      for (int i = 0; i < 4; ++i) {
        int x = now.x + dir[i][0];
        int y = now.y + dir[i][1];
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y]) continue;
        vis[x][y] = true;
        if (now.height > mmap[x][y]) {
          ans += now.height - mmap[x][y];
        }
        pq.push({x, y, max(now.height, mmap[x][y])});
      }
    }
    return ans;
  }
};