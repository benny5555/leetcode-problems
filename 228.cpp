#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  string func(int left, int right) {
    return left == right ? to_string(left)
                         : to_string(left) + "->" + to_string(right);
  }

 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<string> ans;
    int start = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if ((long)nums[i] - (long)nums[i - 1] > 1) {
        ans.push_back(func(nums[start], nums[i - 1]));
        start = i;
      }
    }
    ans.push_back(func(nums[start], nums[nums.size() - 1]));
    return ans;
  }
};