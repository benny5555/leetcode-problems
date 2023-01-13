#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> ans;
  vector<vector<int>> graph;
  vector<bool> vis;
  int cnt[256]{};
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    graph.resize(n);
    ans.resize(n);
    vis.resize(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    dfs(0, labels);
    return ans;
  }
  void dfs(int now, const string& labels) {
    if (vis[now]) return;
    // count of labels which are not under this subtree.
    int prevcnt = cnt[labels[now]];
    vis[now] = true;
    for (auto next : graph[now]) {
      dfs(next, labels);
    }
    // all counts under this subtree;
    ans[now] = ++cnt[labels[now]] - prevcnt;
  }
};