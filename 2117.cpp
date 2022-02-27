#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string abbreviateProduct(int left, int right) {
    long long suf = 1, c = 0, max_suf = 1e12;
    double pre = 1.0;
    for (int i = left; i <= right; ++i) {
      pre *= i;
      while (pre >= 1e5) pre /= 10;
      suf *= i;
      while (suf % 10 == 0) suf /= 10, ++c;
      suf %= max_suf;
    }
    auto ans = to_string(suf);
    return (ans.size() <= 10
                ? ans
                : to_string((int)pre) + "..." + ans.substr(ans.size() - 5)) +
           "e" + to_string(c);
  }
};