#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int largestVariance(string s) {
    int n = s.size();
    int cnt[256]{};
    for (auto c : s) {
      cnt[c]++;
    }
    unordered_set<char> mset(s.begin(), s.end());
    int ans = 0;
    for (auto a : mset) {
      for (auto b : mset) {
        if (a == b) continue;
        int cnta = 0, cntb = 0, remaina = cnt[a];
        for (auto c : s) {
          if (c == a) {
            ++cnta, --remaina;
          }
          if (c == b) {
            ++cntb;
          }
          if (cnta) {
            ans = max(ans, cntb - cnta);
          }
          if (cntb < cnta && remaina >= 1) {
            cntb = cnta = 0;
          }
        }
      }
    }
    return ans;
  }
};