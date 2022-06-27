#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  bool checkTree(TreeNode* root) {
    int left = root->left->val, right = root->right->val, total = root->val;
    return total == left + right;
  }
};