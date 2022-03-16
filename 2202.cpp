#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumTop(vector<int>& nums, int k) {
    int n = nums.size();
    if (k == 0) return n > 0 ? nums.front() : -1;
    if (k == 1) return n == 1 ? -1 : nums[1];
    if (n == 1) return k % 2 ? -1 : nums[0];
    int ans = *max_element(nums.begin(), nums.begin() + min(k - 1, n));
    if (k < n) ans = max(ans, nums[k]);
    return ans;
  }
};