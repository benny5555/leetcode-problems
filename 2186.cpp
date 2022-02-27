#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minSteps(string s, string t) {
    int cnt1[26]{0};
    for (auto c : s) {
      ++cnt1[c - 'a'];
    }
    for (auto c : t) {
      --cnt1[c - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans += abs(cnt1[i]);
    }
    return ans;
  }
};