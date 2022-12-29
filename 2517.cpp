#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int l = 0, r = price.back() - price.front();
    while (l < r) {
      int m = (l + r + 1) / 2, cnt = 1;
      for (int last = 0, i = 1; i < price.size(); ++i) {
        if (price[i] - price[last] >= m) {
          last = i;
          ++cnt;
        }
      }
      if (cnt >= k) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};