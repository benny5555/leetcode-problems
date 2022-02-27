#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    int ans = 0;
    for (auto& s : words) {
      if (s.size() < pref.size()) continue;
      bool flag = true;
      for (int i = 0; i < s.size() && i < pref.size(); ++i) {
        if (s[i] != pref[i]) {
          flag = false;
          break;
        }
      }
      if (flag) ++ans;
    }
    return ans;
  }
};