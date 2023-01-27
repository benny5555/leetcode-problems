#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int now, step;
  };
  pair<int, int> coordinate(int next, int n) {
    int x = (next - 1) / n, y = (next - 1) % n;
    if (x & 1) y = n - 1 - y;
    return {n - 1 - x, y};
  }

 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), edge = n * n;
    queue<node> que;
    que.push({1, 0});
    vector<bool> vis(n * n + 1);
    vis[1] = true;
    while (que.size()) {
      auto [now, step] = que.front();
      que.pop();
      for (int i = 1; i <= 6; ++i) {
        int next = now + i;
        if (next > edge) break;
        auto [x, y] = coordinate(next, n);
        if (board[x][y] > 0) {
          next = board[x][y];
        }
        if (next == edge) return step + 1;
        if (vis[next]) continue;
        vis[next] = true;
        que.push({next, step + 1});
      }
    }
    return -1;
  }
};