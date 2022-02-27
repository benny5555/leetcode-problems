#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  pair<TreeNode*, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return {nullptr, false};
    auto left = dfs(root->left, p, q), right = dfs(root->right, p, q);
    if (left.first && right.first) return {root, true};
    if (root == p || root == q) return {root, left.first || right.first};
    return left.first ? left : right;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto ans = dfs(root, p, q);
    return ans.second ? ans.first : nullptr;
  }
};