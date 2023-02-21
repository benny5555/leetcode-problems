#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    auto left = root->left, right = root->right;
    invertTree(root->left);
    invertTree(root->right);
    root->left = right, root->right = left;
    return root;
  }
};