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
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(),
         [&](auto& a, auto& b) { return a[2] < b[2]; });
    sort(edgeList.begin(), edgeList.end(),
         [&](auto& a, auto& b) { return a[2] < b[2]; });
    UnionFind<int> uf(n);
    int i = 0;
    for (auto& q : queries) {
      int u = q[0], v = q[1], limit = q[2], ind = q[3];
      for (; i < edgeList.size() && edgeList[i][2] < limit; ++i) {
        uf.unite(edgeList[i][0], edgeList[i][1]);
      }
      ans[ind] = uf.find(u) == uf.find(v);
    }
    return ans;
  }
};