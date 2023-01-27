#include <bits/stdc++.h>
using namespace std;
class Solution {
  int ans = INT_MIN;
  vector<vector<int>> children;
  int dfs(const string& s, int now) {
    int largest = 0, second_largest = 0, cur = 0;
    for (auto next : children[now]) {
      cur = dfs(s, next);
      if (s[next] == s[now]) continue;
      if (cur >= largest) {
        second_largest = largest;
        largest = cur;
      } else if (cur > second_largest) {
        second_largest = cur;
      }
    }
    ans = max(ans, largest + second_largest + 1);
    return largest + 1;
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