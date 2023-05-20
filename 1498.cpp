#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0, mod = 1e9 + 7, n = nums.size();
    int pow[100005]{};
    pow[0] = 1;
    for (int i = 1; i < n; ++i) {
      pow[i] = pow[i - 1] * 2 % mod;
    }
    int l = 0, r = n - 1;
    while (l <= r) {
      if (nums[l] + nums[r] > target) {
        --r;
      } else {
        ans = (ans + pow[r - l++]) % mod;
      }
    }
    return ans;
  }
};