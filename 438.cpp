#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int m = s.size(), n = p.size();
    if (m < n) return {};
    vector<int> ans;
    vector<int> cnts(26), cntp(26);
    for (int i = 0; p[i]; ++i) {
      ++cnts[s[i] - 'a'], ++cntp[p[i] - 'a'];
    }
    if (cnts == cntp) ans.push_back(0);
    for (int i = n; i < m; ++i) {
      --cnts[s[i - n] - 'a'], ++cnts[s[i] - 'a'];
      if (cnts == cntp) ans.push_back(i - n + 1);
    }
    return ans;
  }
};