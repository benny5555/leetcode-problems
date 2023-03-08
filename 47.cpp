#include <bits/stdc++.h>
using namespace std;
class Solution {
  //   vector<vector<int>> ans;
  //   void dfs(int depth, vector<int> nums) {
  //     if (depth == nums.size() - 1) {
  //       ans.push_back(nums);
  //       return;
  //     }
  //     for (int i = depth; i < nums.size(); ++i) {
  //       if (i != depth && nums[i] == nums[depth]) continue;
  //       swap(nums[i], nums[depth]);
  //       dfs(depth + 1, nums);
  //     }
  //   }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    // sort(nums.begin(), nums.end());
    // dfs(0, nums);
    // return ans;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do {
      ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
  }
};