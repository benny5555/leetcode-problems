#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

// namespace std;
class Solution {
  vector<vector<int>> children;
  int dfs(const string &s, int &ans, int i) {
    int big1 = 0, big2 = 0;
    for (auto child : children[i]) {
      int cur = dfs(s, ans, child);
      if (s[i] == s[child]) continue;
      if (cur > big2) big2 = cur;
      if (big2 > big1) swap(big1, big2);
    }
    ans = max(ans, big1 + big2 + 1);
    return big1 + 1;
  }

 public:
  int longestPath(vector<int> &parent, string s) {
    int n = s.size();
    children = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
      children[parent[i]].push_back(i);
    }
    int ans = 0;
    dfs(s, ans, 0);
    return ans;
  }
};