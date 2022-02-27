#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  int depth(TreeNode* root) {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }

 public:
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int left = depth(root->left);
    int right = depth(root->right);
    return abs(left - right) <= 1 && isBalanced(root->left) &&
           isBalanced(root->right);
  }
};