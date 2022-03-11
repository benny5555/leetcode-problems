#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int mostFrequent(vector<int>& nums, int key) {
    int cnt[1001]{0};
    int n = nums.size();
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[ans]) {
        ans = nums[i];
      }
    }
    return ans;
  }
};