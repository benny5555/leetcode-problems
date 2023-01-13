#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return root;
  }
};