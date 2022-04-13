#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int triangularSum(vector<int>& nums) {
    int n = nums.size();
    while (n > 1) {
      vector<int> temp(n - 1);
      for (int i = 0; i < temp.size(); ++i) {
        temp[i] = (nums[i] + nums[i + 1]) % 10;
      }
      nums = std::move(temp);
      --n;
    }
    return nums[0];
  }
};