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
  int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_set<int> s;
    int n = isConnected.size();
    UnionFind<int> uf(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j]) {
          uf.unite(i, j);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      s.insert(uf.find(i));
    }
    return (int)s.size();
  }
};