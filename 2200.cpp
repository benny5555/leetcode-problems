#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> ans;
    vector<int> keys;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == key) keys.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      for (int num : keys) {
        if (abs(i - num) <= k) {
          ans.push_back(i);
          break;
        }
      }
    }
    return ans;
  }
};