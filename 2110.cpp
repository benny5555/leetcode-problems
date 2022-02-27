#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long long ans = 0;
    int i = 0, j = 1, pre = 0;
    int n = prices.size();
    while (i < n) {
      while (j < n && prices[pre] - 1 == prices[j]) {
        ++pre, ++j;
      }
      ans += (long long)(j - i) * (j - i + 1) / 2;
      i = j++;
      pre = i;
    }
    return ans;
  }
};