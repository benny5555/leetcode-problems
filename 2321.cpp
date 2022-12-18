#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int kadane(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
      sum = max(nums2[i] - nums1[i], sum + nums2[i] - nums1[i]);
      ans = max(ans, sum);
    }
    return ans;
  }
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(
        accumulate(nums1.begin(), nums1.end(), 0) + kadane(nums1, nums2),
        accumulate(nums2.begin(), nums2.end(), 0) + kadane(nums2, nums1));
  }
};