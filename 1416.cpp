#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dp[100005]{}, mod = 1e9 + 7;

  int dfs(const string &s, long k, int i) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    if (dp[i] != -1) return dp[i];
    long ans = 0, num = 0;
    for (int j = i; j < s.size(); ++j) {
      num = num * 10 + s[j] - '0';
      if (num > k) break;
      ans += dfs(s, k, j + 1);
      ans %= mod;
    }
    return dp[i] = ans;
  }

 public:
  int numberOfArrays(string s, int k) {
    memset(dp, -1, sizeof(dp));
    return dfs(s, k, 0);
  }
};