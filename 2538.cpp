#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    using ll = long long;
    ll ans = 0;
    vector<vector<int>> graph(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    function<vector<ll>(int, int)> dfs = [&](int now, int pre) {
      // cur_max[0]: max pathsum
      // cur_max[1]: max(pathsum - leaf node)
      vector<ll> cur_max = {price[now], 0};
      for (auto& next : graph[now]) {
        if (next != pre) {
          const auto& subtree = dfs(next, now);
          ans = max(ans, cur_max[0] + subtree[1]);
          ans = max(ans, cur_max[1] + subtree[0]);
          cur_max[0] = max(cur_max[0], subtree[0] + price[now]);
          cur_max[1] = max(cur_max[1], subtree[1] + price[now]);
        }
      }
      return cur_max;
    };
    dfs(0, -1);
    return ans;
  }
};