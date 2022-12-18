#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct UnionFind {
  vector<T> parent, size;
  UnionFind(int n) : parent(n), size(n, INT_MAX) {
    iota(parent.begin(), parent.end(), 0);
  }
  T find(T x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(T u, T v, T w) {
    T pu = find(u), pv = find(v);
    size[pv] = min({size[pv], w, size[pu]});

    if (pu != pv) {
      parent[pu] = pv;
    }
  }
  T smallest() { return min(size[find(1)], size[find(parent.size() - 1)]); }
};

class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    UnionFind<int> uf(n + 1);
    for (auto& r : roads) {
      uf.unite(r[0], r[1], r[2]);
    }
    return uf.smallest();
  }
};