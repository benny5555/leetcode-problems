#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  int ans = INT_MIN;
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    auto left = max(0, dfs(root->left)), right = max(0, dfs(root->right));
    ans = max(ans, root->val + left + right);
    return max(left, right) + root->val;
  }

 public:
  int maxPathSum(TreeNode* root) {
    dfs(root);
    return ans;
  }
};