#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string greatestLetter(string s) {
    int cnt[256]{0};
    for (auto c : s) {
      ++cnt[c];
    }
    for (int i = 255; i > -1; --i) {
      if (cnt[i]) {
        if (cnt[i - 'A' + 'a']) {
          string ans;
          ans.push_back(i);
          return ans;
        }
      }
    }
    return "";
  }
};