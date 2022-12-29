#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int mod = 1e9 + 7;
  int countPalindromes(string s) {
    using ll = long long;
    ll pre[10000][10][10]{}, suf[10000][10][10]{}, cnt[10]{}, n = s.size(),
                                                              ans = 0;
    for (int i = 0; i < n; ++i) {
      int c = s[i] - '0';
      if (i) {
        for (int j = 0; j < 10; ++j) {
          for (int k = 0; k < 10; ++k) {
            pre[i][j][k] = pre[i - 1][j][k];
            if (k == c) pre[i][j][k] += cnt[j];
          }
        }
      }
      ++cnt[c];
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = n - 1; i >= 0; --i) {
      int c = s[i] - '0';
      if (i != n - 1) {
        for (int j = 0; j < 10; ++j) {
          for (int k = 0; k < 10; ++k) {
            suf[i][j][k] = suf[i + 1][j][k];
            if (k == c) suf[i][j][k] += cnt[j];
          }
        }
      }
      ++cnt[c];
    }
    for (int i = 2; i < n - 2; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          ans = (ans + 1ll * pre[i - 1][j][k] * suf[i + 1][j][k]) % mod;
        }
      }
    }
    return ans;
  }
};