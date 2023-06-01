#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct UnionFind {
  vector<T> parent;
  T size;
  UnionFind(int n) : parent(n), size(n) {
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
      --size;
    }
  }
};
class Solution {
  bool similar(const string& a, const string& b) {
    int n = 0;
    for (int i = 0; i < a.size() && i < b.size(); ++i) {
      if (a[i] != b[i] && ++n > 2) {
        return false;
      }
    }
    return true;
  }

 public:
  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    UnionFind<int> uf(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (similar(strs[i], strs[j])) {
          uf.unite(i, j);
        }
      }
    }
    return uf.size;
  }
};