#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    vector<int> v;
    v.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) v.push_back(nums[i]);
    }
    int ans = 0;
    for (int i = 1; i < v.size() - 1; ++i) {
      if (v[i] < v[i - 1] && v[i] < v[i + 1] ||
          v[i] > v[i - 1] && v[i] > v[i + 1])
        ++ans;
    }
    return ans;
  }
};