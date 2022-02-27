#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  struct node {
    int x, y, price, step;
    bool operator<(const node& b) const {
      if (step != b.step) {
        return step > b.step;
      } else if (price != b.price) {
        return price > b.price;
      } else if (x != b.x) {
        return x > b.x;
      } else {
        return y > b.y;
      }
    }
  };
  int dir[4][2]{0, 1, 0, -1, 1, 0, -1, 0};

 public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                          vector<int>& pricing,
                                          vector<int>& start, int k) {
    vector<vector<int>> ans;
    priority_queue<node> pq;
    int n = grid.size(), m = grid[0].size();
    int x = start[0], y = start[1], low = pricing[0], high = pricing[1];
    queue<node> que;
    que.push({x, y});
    if (grid[x][y] >= low && grid[x][y] <= high) pq.push({x, y, grid[x][y], 0});
    grid[x][y] = 0;

    while (que.size()) {
      auto temp = que.front();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int xx = temp.x + dir[i][0];
        int yy = temp.y + dir[i][1];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] == 0)
          continue;
        if (grid[xx][yy] >= low && grid[xx][yy] <= high) {
          pq.push({xx, yy, grid[xx][yy], temp.step + 1});
        }
        que.push({xx, yy, grid[xx][yy], temp.step + 1});
        grid[xx][yy] = 0;
      }
    }
    while (pq.size() && k--) {
      ans.push_back({pq.top().x, pq.top().y});
      pq.pop();
    }
    return ans;
  }
};