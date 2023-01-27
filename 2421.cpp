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
#define v vector

 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    v<v<int>> graph(n);
    for (auto& e : edges) {
      if (vals[e[1]] <= vals[e[0]]) graph[e[0]].push_back(e[1]);
      if (vals[e[0]] <= vals[e[1]]) graph[e[1]].push_back(e[0]);
    }
    map<int, v<int>> sameval_ind;
    for (int i = 0; i < n; ++i) {
      sameval_ind[vals[i]].push_back(i);
    }
    int ans = 0;
    UnionFind<int> uf(n);
    for (auto& [val, ind] : sameval_ind) {
      for (auto now : ind) {
        for (auto next : graph[now]) {
          if (next == now) continue;
          uf.unite(now, next);
        }
      }
      unordered_map<int, int> group;
      ans += ind.size();
      for (auto i : ind) {
        group[uf.find(i)]++;
      }
      for (auto& [_, cnt] : group) {
        ans += (cnt * (cnt - 1)) / 2;
      }
    }
    return ans;
  }
};