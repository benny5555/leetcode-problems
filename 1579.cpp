#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct UnionFind {
  vector<T> parent, size;
  int cnt;
  UnionFind(int n) : parent(n), size(n, 1), cnt(n - 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  T find(T x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  bool unite(T u, T v) {
    T pu = find(u), pv = find(v);
    if (pu != pv) {
      parent[pu] = v;
      size[pv] += size[pu];
      --cnt;
      return true;
    }
    return false;
  }
  bool united() { return cnt == 1; }
};

class Solution {
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(),
         [&](auto& a, auto& b) { return a[0] > b[0]; });
    int added = 0;
    UnionFind<int> bob(n + 1), alice(n + 1);
    for (auto& e : edges) {
      int type = e[0], u = e[1], v = e[2];
      switch (type) {
        case 3:
          added += (bob.unite(u, v) | alice.unite(u, v));
          break;
        case 2:
          added += bob.unite(u, v);
          break;
        case 1:
          added += alice.unite(u, v);
          break;
      }
    }
    return (bob.united() && alice.united()) ? (edges.size() - added) : -1;
  }
};