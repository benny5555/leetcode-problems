#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    long sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans = max(ans, (long)ceil((double)sum / (i + 1)));
    }
    return ans;
  }
};