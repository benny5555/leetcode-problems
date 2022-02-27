#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    int ans1 = 0, ans2 = 0;
    int n = favorite.size();
    vector<vector<int>> graph(n);
    vector<int> depth(n, -1);
    for (int i = 0; i < n; ++i) graph[favorite[i]].push_back(i);
    function<int(int)> dfs = [&](int start) {
      if (depth[start] != -1) return depth[start];
      int ans = 0;
      for (int next : graph[start]) ans = max(ans, dfs(next));
      return depth[start] = 1 + ans;
    };
    for (int i = 0; i < n; ++i) {
      if (depth[i] != -1) continue;
      if (favorite[favorite[i]] == i) {
        depth[i] = depth[favorite[i]] = 0;
        int a = 0, b = 0;
        for (int next : graph[i]) {
          if (next == favorite[i]) continue;
          a = max(a, dfs(next));
        }
        for (int next : graph[favorite[i]]) {
          if (next == i) continue;
          b = max(b, dfs(next));
        }
        ans1 += a + b + 2;
      }
    }
    function<tuple<int, int, bool>(int)> dfs2 =
        [&](int start) -> tuple<int, int, bool> {
      if (depth[start] != -1) return {start, depth[start], false};
      depth[start] = 0;
      auto [case2point, dep, met] = dfs2(favorite[start]);
      if (met) {
        depth[start] = 0;
        return {case2point, dep, true};
      }
      return {case2point, depth[start] = 1 + dep, start == case2point};
    };
    for (int i = 0; i < n; ++i) {
      if (depth[i] != -1) continue;
      auto [point, dep, vis] = dfs2(i);
      if (vis) ans2 = max(ans2, dep);
    }
    return max(ans1, ans2);
  }
};