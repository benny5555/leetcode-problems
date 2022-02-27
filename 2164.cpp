#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> ans, odd, even;
    for (int i = 0; i < nums.size(); ++i) {
      if (i & 1) {
        odd.push_back(nums[i]);
      } else {
        even.push_back(nums[i]);
      }
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.begin(), even.end());
    int i = 0;
    for (; i < even.size() && i < odd.size(); ++i) {
      ans.push_back(even[i]);
      ans.push_back(odd[i]);
    }
    if (i < even.size()) ans.push_back(even[i]), ++i;
    return ans;
  }
};