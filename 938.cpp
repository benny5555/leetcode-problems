#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    int left = rangeSumBST(root->left, low, high);
    int right = rangeSumBST(root->right, low, high);
    return (root->val >= low && root->val <= high) ? root->val + left + right
                                                   : left + right;
  }
};