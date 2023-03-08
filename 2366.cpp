#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    long long ans = 0, n = nums.size(), next = nums.back();
    for (int i = n - 2; i >= 0; --i) {
      int cnt = nums[i] / next;
      if (nums[i] % next) {
        ++cnt;
        next = nums[i] / cnt;
      }
      ans += cnt - 1;
    }
    return ans;
  }
};