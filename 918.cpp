#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, mmax = nums[0], mmin = nums[0], cur_max = 0, cur_min = 0;
    for (auto num : nums) {
      cur_max = max(cur_max + num, num);
      mmax = max(mmax, cur_max);
      cur_min = min(cur_min + num, num);
      mmin = min(mmin, cur_min);
      total += num;
    }
    return mmax > 0 ? max(mmax, total - mmin) : mmax;
  }
};