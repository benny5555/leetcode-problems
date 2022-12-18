#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int x, y, val;
    bool operator<(const node& b) const { return val > b.val; }
  };
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};

 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int m = grid.size(), n = grid[0].size();
    priority_queue<node> pq;
    map<int, int> presum{{0, 0}};
    pq.push({0, 0, grid[0][0]});
    grid[0][0] = 0;
    int val = 0;
    while (pq.size()) {
      auto now = pq.top();
      pq.pop();
      val = max(val, now.val);
      ++presum[val];
      for (int i = 0; i < 4; ++i) {
        int x = now.x + dir[i][0];
        int y = now.y + dir[i][1];
        if (x < 0 || y < 0 || x >= m || y >= n || !grid[x][y]) continue;
        pq.push({x, y, grid[x][y]});
        grid[x][y] = 0;
      }
    }

    for (auto iter = presum.begin(); iter != presum.end(); ++iter) {
      if (iter != presum.begin()) {
        iter->second += prev(iter)->second;
      }
    }
    transform(queries.begin(), queries.end(), queries.begin(), [&](int val) {
      auto iter = presum.lower_bound(val);
      return iter == presum.begin() ? 0 : prev(iter)->second;
    });
    return queries;
  }
};