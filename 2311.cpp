#include <bits/stdc++.h>
using namespace std;
class Solution1 {
 public:
  int longestSubsequence(string s, int k) {
    int dp[1024]{0};
    int j = 0;
    for (char& c : s) {
      if (dp[j] * 2 + c - '0' <= k) {
        dp[++j] = dp[j] * 2 + c - '0';
      }
      for (int i = j; i > 0; --i) {
        dp[i] = min(dp[i], dp[i - 1] * 2 + c - '0');
      }
    }
    return j;
  }
};

class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int ans = 0, bin = 1, n = s.size();
    for (int i = n - 1; i > -1; --i) {
      if (s[i] == '0' || bin <= k) {
        ++ans;
        k -= bin * (s[i] - '0');
      }
      if (bin <= k) {
        bin <<= 1;
      }
    }
    return ans;
  }
};