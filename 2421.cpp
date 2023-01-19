#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct UnionFind {
  vector<T> parent, size;
  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  T find(T x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(T u, T v) {
    T pu = find(u), pv = find(v);
    if (pu != pv) {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};
class Solution {
 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int ans = 0, n = vals.size();
    vector<vector<int>> graph(n);
    map<int, vector<int>> samevals_ind;
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      if (vals[u] >= vals[v]) {
        graph[u].push_back(v);
      } else if (vals[v] >= vals[u]) {
        graph[v].push_back(u);
      }
    }
    for (int i = 0; i < n; ++i) {
      samevals_ind[vals[i]].push_back(i);
    }
    UnionFind<int> uf(n);
    for (auto& [val, ind] : samevals_ind) {
      for (int now : ind) {
        for (int next : graph[now]) {
          uf.unite(now, next);
        }
      }
      unordered_map<int, int> group;
      for (auto val : ind) {
        ++group[uf.find(val)];
      }
      ans += ind.size();
      for (auto& [_, cnt] : group) {
        ans += (cnt * (cnt - 1)) / 2;
      }
    }
    return ans;
  }
};