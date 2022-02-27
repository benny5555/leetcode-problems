#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) {
      if (x == parent[x]) return x;
      return parent[x] = find(parent[x]);
    }
    void unite(int u, int v) {
      int pu = find(u), pv = find(v);
      if (pu != pv) {
        parent[pu] = pv;
      }
    }
  };

 public:
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                              vector<vector<int>>& requests) {
    vector<bool> ans;
    UnionFind uf(n);
    for (auto& r : requests) {
      int p = uf.find(r[0]), q = uf.find(r[1]);
      bool flag = true;
      for (auto& ban : restrictions) {
        int u = uf.find(ban[0]), v = uf.find(ban[1]);
        if (u == p && v == q || u == q && v == p) {
          flag = false;
          break;
        }
      }
      ans.push_back(flag);
      if (flag) uf.unite(p, q);
    }
    return ans;
  }
};