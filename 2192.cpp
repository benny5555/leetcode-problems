#include <bits/stdc++.h>
using namespace std;
class Solution1 {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n), graph(n);
    vector<int> indegree(n);
    for (auto& e : edges) {
      ++indegree[e[1]];
      graph[e[0]].push_back(e[1]);
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) {
        que.push(i);
      }
    }
    vector<vector<int>> cnt(n, vector<int>(n));

    while (que.size()) {
      auto temp = que.front();
      que.pop();
      for (auto next : graph[temp]) {
        cnt[next][temp] = 1;
        for (int i = 0; i < n; ++i) {
          if (cnt[temp][i] == 1) cnt[next][i] = 1;
        }
        if (--indegree[next] == 0) {
          que.push(next);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (cnt[i][j]) {
          ans[i].push_back(j);
        }
      }
    }
    return ans;
  }
};
class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n), graph(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
    }
    function<void(int, int)> dfs = [&](int parent, int now) {
      for (auto next : graph[now]) {
        if (ans[next].size() == 0 || ans[next].back() != parent) {
          ans[next].push_back(parent);
          dfs(parent, next);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      dfs(i, i);
    }
    return ans;
  }
};