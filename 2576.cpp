#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    int n = nums.size(), i = 0;
    sort(nums.begin(), nums.end());
    for (int j = n - n / 2; j < n; ++j) {
      i += 2 * nums[i] <= nums[j];
    }
    return 2 * i;
  }
};