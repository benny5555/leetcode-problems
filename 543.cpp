#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int ans = 0;
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return ans;
  }
  int dfs(TreeNode* root, int depth = 0) {
    if (root == nullptr) return 0;
    auto left = dfs(root->left), right = dfs(root->right);
    ans = max(ans, left + right);
    return max(left, right) + 1;
  }
};