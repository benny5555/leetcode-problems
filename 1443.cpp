#include <bits/stdc++.h>
using namespace std;
class Solution {
#define v vector
  v<v<int>> graph;
  v<bool> vis;
  int dfs(int now, v<bool>& hasApple) {
    if (vis[now]) return 0;
    vis[now] = true;
    int childrentime = 0;
    for (auto next : graph[now]) {
      childrentime += dfs(next, hasApple);
    }
    if (childrentime == 0 && hasApple[now] == false) return 0;
    return childrentime + 2;
  }

 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    graph.resize(n);
    vis.resize(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    return max(dfs(0, hasApple) - 2, 0);
  }
};