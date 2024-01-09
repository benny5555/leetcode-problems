#include <bits/stdc++.h>
using namespace std;
class Solution {
  long long func(int n, int ind, int x) {
    long long l = max(0, x - ind), r = max(0, x - (n - 1 - ind)),
              ans = (l + x) * (x - l + 1) / 2 + (r + x) * (x - r + 1) / 2;
    return ans - x;
  }

 public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int l = 0, r = maxSum;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (func(n, index, mid) <= maxSum) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return l + 1;
  }
};