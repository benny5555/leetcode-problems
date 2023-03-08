#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
      m[arr[i]].push_back(i);
    }
    vector<bool> vis(n);
    queue<int> que;
    que.push(0);
    vis[0] = true;
    int step = 0;
    while (que.size()) {
      int sz = que.size();
      for (int _ = 0; _ < sz; ++_) {
        int i = que.front();
        que.pop();
        if (i == n - 1) return step;
        auto& next = m[arr[i]];
        next.push_back(i - 1);
        next.push_back(i + 1);
        for (auto j : next) {
          if (j < 0 || j >= n || vis[j]) continue;
          vis[j] = true;
          que.push(j);
        }
        next.clear();
      }
      ++step;
    }
    return 0;
  }
};