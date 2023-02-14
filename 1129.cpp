#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
#define v vector
    v<int> ans;
    v<v<v<int>>> graph(2, v<v<int>>(n));
    for (auto& r : redEdges) {
      graph[0][r[0]].push_back(r[1]);
    }
    for (auto& b : blueEdges) {
      graph[1][b[0]].push_back(b[1]);
    }
    int mmax = INT_MAX / 2;
    v<v<int>> dis(2, v<int>(n, mmax));
    dis[0][0] = dis[1][0] = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    que.push(make_pair(1, 0));
    while (que.size()) {
      auto [color, now] = que.front();
      que.pop();
      for (auto next : graph[color][now]) {
        if (dis[color ^ 1][next] == mmax) {
          dis[color ^ 1][next] = dis[color][now] + 1;
          que.push(make_pair(color ^ 1, next));
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int d = min(dis[0][i], dis[1][i]);
      ans.push_back(d == mmax ? -1 : d);
    }
    return ans;
  }
};