#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long ans = 0;
    int l = -1, r = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        r = i;
        ans += r - l;
      } else {
        l = i, r = i;
      }
    }
    return ans;
  }
};