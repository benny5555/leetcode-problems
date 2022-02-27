#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> ans;
    for (int num : nums) {
      if (ans.empty() || ans.back() < num)
        ans.push_back(num);
      else
        *lower_bound(ans.begin(), ans.end(), num) = num;
    }
    return ans.size();
  }
};