#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size(), -1);
    unordered_map<int, int> m;
    stack<int> stk;
    for (int num : nums2) {
      while (stk.size() && stk.top() < num) m[stk.top()] = num, stk.pop();
      stk.push(num);
    }
    for (int i = 0; i < nums1.size(); ++i) {
      auto iter = m.find(nums1[i]);
      if (iter != m.end()) {
        ans[i] = iter->second;
      }
    }
    return ans;
  }
};