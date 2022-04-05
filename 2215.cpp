#include <bits/stdc++.h>

#include <unordered_set>
using namespace std;
class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    unordered_set<int> s1(nums1.begin(), nums1.end()),
        s2(nums2.begin(), nums2.end());
    for (auto iter : s1) {
      if (!s2.count(iter)) {
        ans[0].push_back(iter);
      }
    }
    for (auto iter : s2) {
      if (!s1.count(iter)) {
        ans[1].push_back(iter);
      }
    }
    return ans;
  }
};