#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
  vector<int> dfs(TreeNode* root) {
    if (!root) return {-1, -1, -1};
    vector<int> left = dfs(root->left), right = dfs(root->right);
    int ans = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
    return {left[1] + 1, right[0] + 1, ans};
  }

 public:
  int longestZigZag(TreeNode* root) { retun dfs(root)[2]; }
};