#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct UnionFind {
    vector<int> parent, size;
    int cnt;
    UnionFind(int n) : parent(n), size(n, 1), cnt(n) {
      iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
      if (x == parent[x]) return x;
      return parent[x] = find(parent[x]);
    }
    void unite(int u, int v) {
      int pu = find(u), pv = find(v);
      if (pu != pv) {
        --cnt;
        parent[pu] = pv;
        size[pv] += size[pu];
      }
    }
  };

 public:
  vector<int> groupStrings(vector<string>& words) {
    int n = words.size();
    unordered_map<int, int> m;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      int hash = 0;
      for (auto c : words[i]) {
        hash |= 1 << (c - 'a');
      }
      for (int j = 0; j < 26; ++j) {
        if ((1 << j) & hash) {        //已经有这个字母
          int del = hash ^ (1 << j);  //删掉这个字母后可能的字母
          if (m.count(del)) uf.unite(m[del], i);
          // replacement
          for (int k = 0; k < 26; ++k) {
            int temp = del | (1 << k);
            if (temp == del) continue;
            if (m.count(temp)) uf.unite(m[temp], i);
          }
        } else {  //没字母
          int add = hash | (1 << j);
          if (m.count(add)) uf.unite(m[add], i);
        }
      }
      m[hash] = i;
    }
    int mmax = 1;
    for (int i = 0; i < n; ++i) {
      int temp = uf.size[uf.find(i)];
      mmax = max(mmax, temp);
    }
    return {uf.cnt, mmax};
  }
};