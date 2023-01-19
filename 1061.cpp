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
      if (pv > pu) swap(pv, pu);
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};
class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionFind<int> uf(26);
    int n = s1.size();
    for (int i = 0; i < n; ++i) {
      uf.unite(s1[i] - 'a', s2[i] - 'a');
    }
    transform(baseStr.begin(), baseStr.end(), baseStr.begin(),
              [&](char a) { return uf.find(a - 'a') + 'a'; });
    return baseStr;
  }
};