#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
  pair<TreeNode*, int> dfs(TreeNode* root) {
    if (root == nullptr) return {root, 0};
    auto left = dfs(root->left), right = dfs(root->right);
    int left_depth = left.second, right_depth = right.second;
    return {left_depth == right_depth  ? root
            : left_depth > right_depth ? left.first
                                       : right.first,
            max(left_depth, right_depth) + 1};
  }

 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).first; }
};