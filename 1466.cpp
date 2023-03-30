#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> graph;
  vector<int> vis;
  int dfs(int now) {
    vis[now] = true;
    int ans = 0;
    for (auto next : graph[now]) {
      if (!vis[abs(next)]) {
        vis[abs(next)] = true;
        ans += dfs(abs(next)) + (next > 0);
      }
    }
    return ans;
  }

 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    graph.resize(n);
    vis.resize(n);
    for (auto& c : connections) {
      graph[c[0]].push_back(c[1]);
      graph[c[1]].push_back(-c[0]);
    }
    return dfs(0);
  }
};