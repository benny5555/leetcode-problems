#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  pair<TreeNode*, int> dfs(TreeNode* root) {
    if (!root) return {nullptr, 0};
    auto left = dfs(root->left), right = dfs(root->right);
    if (left.second > right.second) return {left.first, left.second + 1};
    if (right.second > left.second) return {right.first, right.second + 1};
    return {root, left.second + 1};
  }

 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).first; }
};