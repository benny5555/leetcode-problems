#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0, curEnd = 0, curFarthest = 0, n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      curFarthest = max(curFarthest, i + nums[i]);
      if (i == curEnd) {
        ++ans;
        curEnd = curFarthest;
      }
    }
    return ans;
  }
};