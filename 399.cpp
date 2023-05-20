#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int> parent;
  vector<double> weight;

  UnionFind(int n) : parent(n), weight(n, 1.0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    if (x != parent[x]) {
      int origin = parent[x];
      parent[x] = find(parent[x]);
      weight[x] *= weight[origin];
    }
    return parent[x];
  }
  double connected(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return weight[x] / weight[y];
    }
    return -1.00000;
  }
  void unite(int x, int y, double value) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }
    parent[px] = py;
    weight[px] = weight[y] * value / weight[x];
  }
};
class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    int n = equations.size();
    UnionFind uf(2 * n);
    unordered_map<string, int> m;
    int id = 0;
    for (int i = 0; i < n; ++i) {
      auto &a = equations[i][0], &b = equations[i][1];
      if (!m.count(a)) {
        m[a] = id++;
      }
      if (!m.count(b)) {
        m[b] = id++;
      }
      uf.unite(m[a], m[b], values[i]);
    }
    vector<double> ans;
    for (auto& q : queries) {
      auto &a = q[0], &b = q[1];
      if (m.count(a) && m.count(b)) {
        ans.push_back(uf.connected(m[a], m[b]));
      } else {
        ans.push_back(-1.0);
      }
    }
    return ans;
  }
};