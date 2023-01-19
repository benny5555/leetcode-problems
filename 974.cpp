#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int presum = 0, ans = 0;
    for (int num : nums) {
      presum = (presum + a % k + k) % k;
      ans += cnt[presum]++;
    }
    return ans;
  }
};