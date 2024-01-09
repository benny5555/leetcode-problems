#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  int ans = INT_MAX;
  void dfs(TreeNode* root, int& val) {
    if (root->left) {
      dfs(root->left, val);
    }
    if (val >= 0) {
      ans = min(ans, abs(root->val - val));
    }
    val = root->val;
    if (root->right) {
      dfs(root->right, val);
    }
  }

 public:
  int getMinimumDifference(TreeNode* root) {
    int val = -1;
    dfs(root, val);
    return ans;
  }
};