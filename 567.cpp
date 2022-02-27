#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int cnt[256]{0};
    for (auto c : s1) {
      --cnt[c];
    }
    int i = 0, j = 0, n = s1.size(), m = s2.size();
    for (; j < m; ++j) {
      ++cnt[s2[j]];
      while (cnt[s2[j]] > 0) {
        --cnt[s2[i++]];
      }
      if (j - i + 1 == n) return true;
    }
    return false;
  }
};