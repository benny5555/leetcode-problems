#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> presum;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      presum[i] = sum;
    }
    for (int i = 0; i < n; ++i) {
      // left;
      ans[i] += (i + 1) * (nums[i]) - presum[i];
      // right
      ans[i] += presum[n - 1] - presum[i] - nums[i] * (n - 1 - i);
    }
    return ans;
  }
};