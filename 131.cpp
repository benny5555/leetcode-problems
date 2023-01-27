#include <bits/stdc++.h>
using namespace std;
class Solution {
#define v vector
  v<v<string>> ans;
  v<string> temp;
  v<v<bool>> dp;
  int n;
  void dfs(int i, const string &s) {
    if (i == n) {
      ans.push_back(temp);
      return;
    }
    for (int j = i; j < n; ++j) {
      if (dp[i][j]) {
        temp.push_back(s.substr(i, j - i + 1));
        dfs(j + 1, s);
        temp.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    n = s.size();
    dp.assign(n, v<bool>(n, true));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
      }
    }
    dfs(0, s);
    return ans;
  }
};