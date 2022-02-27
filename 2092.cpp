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
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    vector<int> ans;
    UnionFind uf(n);
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });
    uf.unite(0, firstPerson);
    for (int i = 0; i < meetings.size();) {
      int time = meetings[i][2];
      vector<int> temp;
      while (i < meetings.size() && meetings[i][2] == time) {
        temp.push_back(meetings[i][0]);
        temp.push_back(meetings[i][1]);
        uf.unite(meetings[i][1], meetings[i][0]);
        ++i;
      }
      for (int num : temp) {
        if (uf.find(num) != uf.find(0)) uf.parent[num] = num;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (uf.find(0) == uf.find(i)) ans.push_back(i);
    }
    return ans;
  }
};