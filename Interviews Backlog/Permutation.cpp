/*dfs permutation->leetcode 491*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
#define v vector
  v<v<int>> ans;
  v<int> temp;
  void dfs(int ind, v<int>& nums) {
    unordered_set<int> s;
    for (int i = ind; i < nums.size(); ++i) {
      if ((temp.empty() || nums[i] >= temp.back()) && !s.count(nums[i])) {
        temp.push_back(nums[i]);
        if (temp.size() > 1) ans.push_back(temp);
        dfs(i + 1, nums);
        temp.pop_back();
        s.insert(nums[i]);
      }
    }
  }

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    dfs(0, nums);
    return ans;
  }
};