#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  bitset<100> state[100];
  bool vis[100];
  int n, ans;
  void dfs(int start) {
    if (vis[start]) return;
    vis[start] = 1;
    for (int i = 0; i < n; ++i) {
      if (state[start][i]) {
        dfs(i);
        state[start] |= state[i];
      }
    }
  }

 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    n = bombs.size();
    for (int i = 0; i < n; ++i) {
      state[i][i] = 1;
      for (int j = i + 1; j < n; ++j) {
        double x1 = bombs[i][0], x2 = bombs[j][0], y1 = bombs[i][1],
               y2 = bombs[j][1];
        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (dist <= bombs[i][2]) state[i][j] = 1;
        if (dist <= bombs[j][2]) state[j][i] = 1;
      }
    }
    for (int i = 0; i < n; ++i) dfs(i);
    for (int i = 0; i < n; ++i)
      if (state[i].count() > ans) ans = state[i].count();
    return ans;
  }
};