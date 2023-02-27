#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int mmin = INT_MAX;
    int ans = 0;
    for (auto x : prices) {
      mmin = min(mmin, x);
      ans = max(ans, x - mmin);
    }
    return ans;
  }
};