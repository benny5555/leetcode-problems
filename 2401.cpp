#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size(), ans = 1, temp = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      while ((temp & nums[j]) != 0) {
        temp ^= nums[i++];
      }
      temp |= nums[j];
      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};