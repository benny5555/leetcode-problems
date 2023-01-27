#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    int now, cost, step;
    bool operator<(const node& b) const { return cost > b.cost; }
  };

 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& f : flights) {
      graph[f[0]].push_back({f[1], f[2]});
    }
    vector<int> dis(n, INT_MAX);
    priority_queue<node> pq;
    pq.push({src, 0, 0});
    while (pq.size()) {
      auto [now, cost, step] = pq.top();
      pq.pop();
      if (now == dst) return cost;
      if (dis[now] < step) continue;
      dis[now] = step;
      if (step > k) continue;
      for (auto& [next, next_cost] : graph[now]) {
        pq.push({next, cost + next_cost, step + 1});
      }
      return -1;
    }
  }
};