#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = INT_MIN;
    int mmin = INT_MAX;
    for (auto x : prices) {
      if (x < mmin) mmin = x;
      if (x - mmin > ans) ans = x - mmin;
    }
    return ans;
  }
};