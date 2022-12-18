#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct UnionFind {
  vector<T> parent, size;
  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  T find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu != pv) {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};

class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    long long ans = 0;
    UnionFind<int> uf(n);
    for (auto& edge : edges) {
      uf.unite(edge[0], edge[1]);
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m[uf.find(i)]++;
    }
    for (auto iter : m) {
      n -= iter.second;
      ans += (long long)((long long)iter.second * n);
    }
    return ans;
  }
};

class Solution1 {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    long long ans = 0;
    vector<vector<int>> m(n);
    for (auto& edge : edges) {
      m[edge[0]].push_back(edge[1]);
      m[edge[1]].push_back(edge[0]);
    }
    ans = ((long long)n * (n - 1)) / 2;
    vector<int> vis(n);
    function<void(int, long long&)> dfs = [&](int node, long long& cnt) {
      vis[node] = 1;
      ++cnt;
      for (auto& next : m[node]) {
        if (!vis[next]) {
          dfs(next, cnt);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        long long cnt = 0;
        dfs(i, cnt);
        ans -= (cnt * (cnt - 1)) / 2;
      }
    }
    return ans;
  }
};