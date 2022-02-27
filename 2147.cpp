#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numberOfWays(string s) {
    long long ans = 1, mod = 1e9 + 7, cnt = 0, j = 0;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == 'S') {
        if (++cnt > 2 && cnt % 2 == 1) {
          ans = ans * (i - j) % mod;
        }
        j = i;
      }
    }
    return cnt % 2 == 0 && cnt > 0 ? ans : 0;
  }
};