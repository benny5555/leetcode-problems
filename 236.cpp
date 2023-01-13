#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    auto left = lowestCommonAncestor(root->left, p, q),
         right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return !left ? right : left;
  }
};