#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1);
    for (auto& d : dislikes) {
      graph[d[0]].push_back(d[1]);
      graph[d[1]].push_back(d[0]);
    }
    function<bool(int, int)> dfs = [&](int now, int c) {
      color[now] = c;
      for (auto next : graph[now]) {
        if (color[next] == 0) {
          return dfs(next, -c);
        } else if (color[next] == c) {
          return false;
        }
      }
      return true;
    };
    for (int i = 1; i <= n; ++i) {
      color = vector<int>(n + 1);
      cout << endl;
      if (dfs(i, 1) == false) return false;
    }
    return true;
  }
};