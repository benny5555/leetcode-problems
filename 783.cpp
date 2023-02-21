#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  int ans = INT_MAX, pre = -1;

 public:
  int minDiffInBST(TreeNode* root) {
    if (root->left) {
      minDiffInBST(root->left);
    }
    if (pre >= 0) {
      ans = min(ans, root->val - pre);
    }
    pre = root->val;
    if (root->right) {
      minDiffInBST(root->right);
    }
    return ans;
  }
};