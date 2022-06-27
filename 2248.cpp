#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> m;
    for (auto& list : nums) {
      for (auto num : list) {
        ++m[num];
      }
    }
    for (auto iter : m) {
      if (iter.second == n) ans.push_back(iter.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};