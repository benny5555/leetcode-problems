#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size(), ans = 0, target = 0;
    for (int x : nums) {
      target |= x;
    }
    for (int state = 1; state < (1 << n); ++state) {
      int temp = 0;
      for (int i = 0; i < n; ++i) {
        if (state & (1 << i)) {
          temp |= nums[i];
        }
      }
      if (temp == target) {
        ++ans;
      }
    }
    return ans;
  }
};