#include <bits/stdc++.h>
using namespace std;
class Solution {
  using ll = long long;
  ll ans = 0;
  int s;
  vector<vector<int>> graph;
  int dfs(int now, int prev) {
    int people = 1;
    for (auto next : graph[now]) {
      if (next == prev) continue;
      people += dfs(next, now);
    }
    if (now != 0) {
      ans += (people + s - 1) / s;
    }
    return people;
  }

 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    s = seats;
    graph.resize(roads.size() + 1);
    for (auto& r : roads) {
      graph[r[0]].push_back(r[1]);
      graph[r[1]].push_back(r[0]);
    }
    dfs(0, -1);
    return ans;
  }
};