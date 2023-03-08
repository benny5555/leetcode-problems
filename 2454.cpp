#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1), stk1, stk2, temp;
    for (int i = 0; i < n; ++i) {
      while (stk2.size() && nums[stk2.back()] < nums[i]) {
        ans[stk2.back()] = nums[i];
        stk2.pop_back();
      }
      while (stk1.size() && nums[stk1.back()] < nums[i]) {
        temp.push_back(stk1.back());
        stk1.pop_back();
      }
      if (temp.size()) {
        stk2.insert(stk2.end(), temp.rbegin(), temp.rend());
        temp.clear();
      }
      stk1.push_back(i);
    }
    return ans;
  }
};