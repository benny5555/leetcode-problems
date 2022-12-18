#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int maxAncestorDiff(TreeNode* root, int curMax = INT_MIN,
                      int curMin = INT_MAX) {
    if (root == nullptr) {
      return curMax - curMin;
    }
    curMax = max(curMax, root->val);
    curMin = min(curMin, root->val);
    int left = maxAncestorDiff(root->left, curMax, curMin);
    int right = maxAncestorDiff(root->right, curMax, curMin);
    return max(left, right);
  }
};