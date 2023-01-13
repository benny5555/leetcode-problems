#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  bool find = false;
  TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    auto left = dfs(root->left, p, q), right = dfs(root->right, p, q);
    if (left && right) {
      find = true;
      return root;
    }
    if (root == p || root == q) {
      find = left || right;
      return root;
    }
    return left ? left : right;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto ans = dfs(root, p, q);
    return find ? ans : nullptr;
  }
};