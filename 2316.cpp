#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> graph;
  vector<bool> vis;
  long long cnt = 0;
  void dfs(int now) {
    vis[now] = true;
    ++cnt;
    for (auto next : graph[now]) {
      if (!vis[next]) {
        dfs(next);
      }
    }
  }

 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    long long ans = ((long long)n * (n - 1)) / 2;
    graph.resize(n);
    vis.resize(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        cnt = 0;
        dfs(i);
        ans -= (cnt * (cnt - 1)) / 2;
      }
    }
    return ans;
  }
};