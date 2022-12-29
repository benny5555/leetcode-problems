#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    if (source == destination) return true;
    vector<unordered_set<int>> graph(n);
    bool vis[200005]{};
    for (auto& e : edges) {
      graph[e[0]].insert(e[1]);
      graph[e[1]].insert(e[0]);
    }
    queue<int> que;
    que.push(source);
    vis[source] = true;
    while (que.size()) {
      auto now = que.front();
      que.pop();
      if (graph[now].count(destination)) return true;
      for (auto next : graph[now]) {
        if (vis[next]) continue;
        que.push(next);
        vis[next] = true;
      }
    }
    return false;
  }
};