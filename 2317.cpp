#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maximumXOR(vector<int>& nums) {
    /*
    int ans = 0;
    for (auto i : nums) {
      ans |= i;
    }
    return ans;
    */
    return reduce(nums.begin(), nums.end(), 0, bit_or());
  }
};