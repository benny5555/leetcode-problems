#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int ans = 0;
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    auto left = dfs(root->left), right = dfs(root->right);
    if (root->left && root->left->val == root->val) {
      ++left;
    } else {
      left = 0;
    }
    if (root->right && root->right->val == root->val) {
      ++right;
    } else {
      right = 0;
    }
    ans = max(ans, left + right);
    return max(left, right);
  }
  int longestUnivaluePath(TreeNode* root) {
    dfs(root);
    return ans;
  }
};