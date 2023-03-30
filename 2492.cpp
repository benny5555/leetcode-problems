#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int> parent, size;
  UnionFind(int n) : parent(n), size(n, INT_MAX) {
    iota(parent.begin(), parent.end(), 0);
  }
  void unite(int u, int v, int w) {
    int pu = find(u), pv = find(v);
    size[pv] = min({size[pv], w, size[pu]});
    if (pu != pv) {
      parent[pu] = pv;
    }
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  int smallest() { return min(size[find(1)], size[find(parent.size() - 1)]); }
};
class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    UnionFind uf(n + 1);
    for (auto& r : roads) {
      uf.unite(r[0], r[1], r[2]);
    }
    return uf.smallest();
  }
};