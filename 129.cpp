#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  int dfs(TreeNode* root, int cur) {
    if (!root) return 0;
    cur = cur * 10 + root->val;
    if (!root->left & !root->right) return cur;
    return dfs(root->left, cur) + dfs(root->right, cur);
  }

 public:
  int sumNumbers(TreeNode* root) { return dfs(root, 0); }
};