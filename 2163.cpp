#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimumDifference(vector<int>& nums) {
    long long ans = LLONG_MAX, n = nums.size() / 3, left = 0, right = 0;
    vector<long long> rsum(nums.size());
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    for (int i = nums.size() - 1; i >= n; --i) {
      right += nums[i];
      r.push(nums[i]);
      if (r.size() > n) {
        right -= r.top();
        r.pop();
      }
      if (r.size() == n) {
        rsum[i] = right;
      }
    }
    for (int i = 0; i < nums.size() - n; ++i) {
      left += nums[i];
      l.push(nums[i]);
      if (l.size() > n) {
        left -= l.top();
        l.pop();
      }
      if (l.size() == n) {
        ans = min(ans, left - rsum[i + 1]);
      }
    }
    return ans;
  }
};