#include <bits/stdc++.h>
using namespace std;
class Solution {
  unordered_set<char> prime{'2', '3', '5', '7'};
  int dp[1005][2][1005], mod = 1e9 + 7;

 public:
  int beautifulPartitions(string s, int k, int minLength) {
    memset(dp, -1, sizeof(dp));
    return dfs(0, k, minLength, s, true);
  }
  int dfs(int i, int k, int minLength, const string &s, bool start) {
    if (i == s.size()) return k == 0;
    if (i > s.size() || k == 0 || start && !prime.count(s[i])) return 0;
    if (dp[i][start][k] != -1) return dp[i][start][k];
    int ans = 0;
    if (prime.count(s[i])) {
      if (start) {
        ans = dfs(i + minLength - 1, k, minLength, s, false);
      } else {
        ans = dfs(i + 1, k, minLength, s, false);
      }
    } else {
      ans = (dfs(i + 1, k - 1, minLength, s, true) +
             dfs(i + 1, k, minLength, s, false)) %
            mod;
    }
    return dp[i][start][k] = ans;
  }
};