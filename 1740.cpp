#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int ans = -1;
  int dfs(TreeNode* root, int p, int q) {
    if (!root) return -1;
    int left = dfs(root->left, p, q), right = dfs(root->right, p, q);
    if (root->val == p || root->val == q) {
      if (left < 0 && right < 0) return 0;
      ans = 1 + (left >= 0 ? left : right);
      return -1;
    }
    if (left >= 0 && right >= 0) {
      ans = left + right + 2;
      return -1;
    }
    if (left >= 0) return left + 1;
    if (right >= 0) return right + 1;
    return -1;
  }
  int findDistance(TreeNode* root, int p, int q) {
    if (p == q) return 0;
    dfs(root, p, q);
    return ans;
  }
};