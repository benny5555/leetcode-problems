#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    long n = nums.size(), left = nums.front(), right = nums.back(), ans = 0;
    for (int i = 0, j = n - 1; i < j;) {
      if (left == right) {
        left = nums[++i];
        right = nums[--j];
      } else if (left < right) {
        left += nums[++i];
        ++ans;
      } else {
        right += nums[--j];
        ++ans;
      }
    }
    return ans;
  }
};