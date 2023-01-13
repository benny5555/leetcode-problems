#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  struct node {
    TreeNode* treenode;
    int depth;
  };
  node dfs(TreeNode* root) {
    if (!root) return {root, 0};
    auto left = dfs(root->left), right = dfs(root->right);
    if (left.depth > right.depth) return {left.treenode, left.depth + 1};
    if (right.depth > left.depth) return {right.treenode, right.depth + 1};
    return {root, left.depth + 1};
  }

 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).treenode; }
};