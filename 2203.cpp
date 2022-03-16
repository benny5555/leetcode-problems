#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct node {
    long long v, w;
    node(long long next, long long weight) : v(next), w(weight) {}
    bool operator<(const node& b) const { return w > b.w; }
  };

 public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int a, int b,
                          int dest) {
    vector<vector<node>> g(n), rg(n);
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      g[u].emplace_back(node(v, w));
      rg[v].emplace_back(node(u, w));
    }
    long long INF = LLONG_MAX / 4;
    vector<long long> da(n, INF), db(n, INF), dd(n, INF);
    auto dijkstra = [&](vector<vector<node>>& graph, int start,
                        vector<long long>& dist) {
      priority_queue<node> pq;
      dist[start] = 0;
      pq.emplace(node(start, 0));
      while (pq.size()) {
        long long now = pq.top().v, cost = pq.top().w;
        pq.pop();
        if (cost > dist[now]) continue;
        for (auto& n : graph[now]) {
          auto next = n.v, weight = n.w;
          if (dist[next] > dist[now] + weight) {
            dist[next] = dist[now] + weight;
            pq.emplace(node(next, dist[next]));
          }
        }
      }
    };
    dijkstra(g, a, da);
    dijkstra(g, b, db);
    dijkstra(rg, dest, dd);
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      if (da[i] == INF || db[i] == INF || dd[i] == INF) continue;
      ans = min(ans, da[i] + db[i] + dd[i]);
    }
    return ans == LLONG_MAX ? -1 : ans;
  }
};