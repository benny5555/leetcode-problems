#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int mmin = INT_MAX, smin = INT_MAX;
    for (int x : nums) {
      if (x <= mmin) {
        mmin = x;
      } else if (x <= smin) {
        smin = x;
      } else {
        return true;
      }
    }
    return false;
  }
};