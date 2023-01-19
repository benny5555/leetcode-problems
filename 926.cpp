#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int one = 0, zero = 0;
    for (auto c : s) {
      if (c == '1') {
        ++one;
      } else {
        ++zero;
      }
      zero = min(one, zero);
    }
    return zero;
  }
};