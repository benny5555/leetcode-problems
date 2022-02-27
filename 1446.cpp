#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxPower(string s) {
    int ans = 0;
    int i = 0, j = 0, n = s.size();
    while (i < n) {
      while (j < n && s[j] == s[i]) ++j;
      ans = max(ans, j - i);
      i = j;
    }
    return ans;
  }
};