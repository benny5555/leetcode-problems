#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
#define v vector
    using ll = long long;
    v<v<int>> graph(n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    ll ans = 0;
    function<v<ll>(int, int)> dfs = [&](int now, int pre) {
      v<ll> cur({price[now], 0});
      for (auto next : graph[now]) {
        if (next != pre) {
          auto sub = dfs(next, now);
          ans = max({ans, cur[0] + sub[1], cur[1] + sub[0]});
          cur[0] = max(cur[0], sub[0] + price[now]);
          cur[1] = max(cur[1], sub[1] + price[now]);
        }
      }
      return cur;
    };
    dfs(0, -1);
    return ans;
  }
};