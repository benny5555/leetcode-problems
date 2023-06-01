#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  bool dfs(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return dfs(left->left, right->right) && dfs(left->right, right->left);
  }

 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return dfs(root->left, root->right);
  }
};