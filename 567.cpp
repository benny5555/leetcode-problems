#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int m = s1.size(), n = s2.size(), cnt[256]{}, i = 0, j = 0;
    for (auto c : s1) {
      --cnt[c];
    }
    for (; j < n; ++j) {
      ++cnt[s2[j]];
      while (cnt[s2[j]] > 0) {
        --cnt[s2[i++]];
      }
      if (j - i + 1 == m) return true;
    }
    return false;
  }
};