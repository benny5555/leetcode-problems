#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int p = find(nums.begin(), nums.end(), k) - nums.begin();
    for (int i = p, balance = 0; i < nums.size(); ++i) {
      balance += nums[i] == k ? 0 : nums[i] < k ? -1 : 1;
      m[balance]++;
    }
    int ans = 0;
    for (int i = p, balance = 0; i >= 0; --i) {
      balance += nums[i] == k ? 0 : nums[i] < k ? -1 : 1;
      ans += m[-balance] + m[-balance + 1];
    }
    return ans;
  }
};