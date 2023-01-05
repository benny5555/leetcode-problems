#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    using ll = long long;
    unordered_map<int, int> m;
    int n = nums.size();
    ll ans = 0, temp = 0;
    for (int i = 0; i < k; ++i) {
      ++m[nums[i]];
      temp += nums[i];
    }
    if (m.size() == k) ans += temp;
    for (int i = k; i < n; ++i) {
      ++m[nums[i]];
      if (--m[nums[i - k]] == 0) m.erase(nums[i - k]);
      temp += nums[i];
      temp -= nums[i - k];
      if (m.size() == k) {
        if (temp > ans) ans = temp;
      }
    }
    return ans;
  }
};