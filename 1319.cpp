#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> graph;
  vector<int> vis;
  void dfs(int now) {
    for (auto next : graph[now]) {
      if (!vis[next]) {
        vis[next] = true;
        dfs(next);
      }
    }
  }

 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    graph.resize(n);
    vis.resize(n);
    for (auto& c : connections) {
      graph[c[0]].push_back(c[1]);
      graph[c[1]].push_back(c[0]);
    }
    int not_connected = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        dfs(i);
        ++not_connected;
      }
    }
    return not_connected - 1;
  }
};