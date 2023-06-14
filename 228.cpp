#include <bits/stdc++.h>
using namespace std;
class Solution {
  string func(vector<int>& nums, int left, int right) {
    return left == right
               ? to_string(nums[left])
               : to_string(nums[left]) + "->" + to_string(nums[right]);
  }

 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) return {};
    int last = 0, n = nums.size();
    vector<string> ans;
    for (int i = 1; i < n; ++i) {
      if ((long)nums[i] - (long)nums[i - 1] > 1) {
        ans.push_back(func(nums, last, i - 1));
        last = i;
      }
    }
    ans.push_back(func(nums, last, n - 1));
    return ans;
  }
};