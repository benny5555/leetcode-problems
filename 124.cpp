#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int ans = INT_MIN;
  int dfs(TreeNode* root) {
    if (!root) return 0;
    int left = max(dfs(root->left), 0), right = max(dfs(root->right), 0);
    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
  }
  int maxPathSum(TreeNode* root) {
    dfs(root);
    return ans;
  }
};