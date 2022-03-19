#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans = 0, cnt1 = 0, cnt2 = 0;
    for (auto c : text) {
      if (c == pattern[1]) {
        ans += cnt1;
        cnt2++;
      }
      if (c == pattern[0]) {
        ++cnt1;
      }
    }
    return ans + max(cnt1, cnt2);
  }
};