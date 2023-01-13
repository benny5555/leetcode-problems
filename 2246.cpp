#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> children;
  int ans = 0;
  int dfs(const string& s, int now) {
    // count the subtree's longest paths.
    int sub1 = 0, sub2 = 0;
    for (auto next : children[now]) {
      int cur = dfs(s, next);
      if (s[now] == s[next]) continue;
      if (cur > sub2) sub2 = cur;
      if (sub2 > sub1) swap(sub1, sub2);
    }
    ans = max(ans, sub1 + sub2 + 1);
    return sub1 + 1;
  }

 public:
  int longestPath(vector<int>& parent, string s) {
    int n = s.size();
    children.resize(n);
    for (int i = 1; i < n; ++i) {
      children[parent[i]].push_back(i);
    }
    dfs(s, 0);
    return ans;
  }
};