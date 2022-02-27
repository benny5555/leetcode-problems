#include <bits/stdc++.h>
using namespace std;
class Solution {
  string func(int left, int right) {
    return left == right ? to_string(left)
                         : to_string(left) + "->" + to_string(right);
  }

 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ans;
    int pre = lower - 1;
    int n = nums.size();
    for (int i = 0; i <= n; ++i) {
      int cur = i == n ? upper + 1 : nums[i];
      if (cur - pre > 1) {
        ans.push_back(func(pre + 1, cur - 1));
      }
      pre = cur;
    }
    return ans;
  }
};