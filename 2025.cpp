#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int waysToPartition(vector<int>& nums, int k) {
    using ll = long long;
    int n = nums.size();
    vector<ll> prefix(n), suffix(n);
    unordered_map<ll, ll> left, right;
    prefix[0] = nums[0], suffix[n - 1] = nums[n - 1];
    for (int i = 1; i < n - 1; ++i) {
      prefix[i] = prefix[i - 1] + nums[i];
      suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
    }
    for (int i = 0; i < n - 1; ++i) {
      right[prefix[i] - suffix[i + 1]]++;
    }
    ll ans = 0;
    if (right.count(0)) {
      ans = right[0];
    }
    for (int i = 0; i < n; ++i) {
      ll diff = k - nums[i], temp = 0;
      if (right.count(-diff)) temp += right[-diff];
      if (left.count(diff)) temp += left[diff];
      ans = max(ans, temp);
      if (i < n - 1) {
        ll t = prefix[i] - suffix[i + 1];
        ++left[t], --right[t];
        if (right[t] == 0) {
          right.erase(t);
        }
      }
    }
    return ans;
  }
};