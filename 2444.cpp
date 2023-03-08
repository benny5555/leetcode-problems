#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0, n = nums.size(), min_ind = -1, max_ind = -1,
              last_bad = -1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < minK || nums[i] > maxK) {
        last_bad = i;
      }
      if (nums[i] == minK) {
        min_ind = i;
      }
      if (nums[i] == maxK) {
        max_ind = i;
      }
      ans += max(0ll, min(min_ind, max_ind) - last_bad);
    }
    return ans;
  }
};