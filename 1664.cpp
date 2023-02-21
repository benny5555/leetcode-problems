#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int oddsum = 0, evensum = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        oddsum += nums[i];
      } else {
        evensum += nums[i];
      }
    }
    int ans = 0, temp_odd = 0, temp_even = 0;
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        oddsum -= nums[i];
        ans += temp_odd + evensum == temp_even + oddsum;
        temp_odd += nums[i];
      } else {
        evensum -= nums[i];
        ans += temp_odd + evensum == temp_even + oddsum;
        temp_even += nums[i];
      }
    }
    return ans;
  }
};