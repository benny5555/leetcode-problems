#include <bits/stdc++.h>
using namespace std;
class Solution {
#define v vector
  v<v<int>> graph;
  v<int> disFromBob;
  int n, bob_point;
  int dfs(int now, int parent, int depth, v<int>& amount) {
    int ans = 0, maxChild = INT_MIN;
    if (now == bob_point) disFromBob[now] = 0;
    for (auto next : graph[now]) {
      if (next == parent) continue;
      maxChild = max(maxChild, dfs(next, now, depth + 1, amount));
      disFromBob[now] = min(disFromBob[now], disFromBob[next] + 1);
    }
    if (disFromBob[now] > depth) ans += amount[now];
    if (disFromBob[now] == depth) ans += amount[now] / 2;
    if (maxChild == INT_MIN) return ans;
    return ans + maxChild;
  }

 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    n = amount.size(), bob_point = bob;
    graph.resize(n);
    disFromBob.resize(n, n);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    return dfs(0, 0, 0, amount);
  }
};