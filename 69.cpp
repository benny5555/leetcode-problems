#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int mySqrt(int x) {
    if (!x) return 0;
    long long l = 1, r = INT_MAX;
    while (l < r) {
      auto mid = (l + r + 1) / 2;
      if (mid * mid > x)
        r = mid - 1;
      else
        l = mid;
    }
    return l;
  }
};