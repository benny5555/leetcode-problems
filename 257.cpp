#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  vector<string> ans;
  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return ans;
    dfs(root, to_string(root->val));
    return ans;
  }
  void dfs(TreeNode* root, string temp) {
    if (!root->left && !root->right) {
      ans.push_back(temp);
      return;
    }
    if (root->left) dfs(root->left, temp + "->" + to_string(root->left->val));
    if (root->right)
      dfs(root->right, temp + "->" + to_string(root->right->val));
  }
};