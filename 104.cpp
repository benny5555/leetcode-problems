#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};