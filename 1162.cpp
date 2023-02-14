#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> que;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          que.push(make_pair(i - 1, j));
          que.push(make_pair(i + 1, j));
          que.push(make_pair(i, j + 1));
          que.push(make_pair(i, j - 1));
        }
      }
    }
    int ans = 0;
    while (que.size()) {
      ++ans;
      int k = que.size();
      for (int _ = 0; _ < k; ++_) {
        auto [x, y] = que.front();
        que.pop();
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y]) continue;
        grid[x][y] = 1;
        que.push(make_pair(x - 1, y));
        que.push(make_pair(x + 1, y));
        que.push(make_pair(x, y + 1));
        que.push(make_pair(x, y - 1));
      }
    }
    return ans == 1 ? -1 : ans - 1;
  }
};