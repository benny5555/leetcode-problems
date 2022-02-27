#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    auto left = invertTree(root->right);
    auto right = invertTree(root->left);
    root->left = left, root->right = right;
    return root;
  }
};