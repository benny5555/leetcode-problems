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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    s1.push(root1), s2.push(root2);
    while (s1.size() && s2.size()) {
      if (dfs(s1) != dfs(s2)) return false;
    }
    return s1.empty() == s2.empty();
  }
  int dfs(stack<TreeNode*>& s) {
    while (1) {
      auto node = s.top();
      s.pop();
      if (node->left) s.push(node->left);
      if (node->right) s.push(node->right);
      if (!node->left && !node->right) return node->val;
    }
  }
};