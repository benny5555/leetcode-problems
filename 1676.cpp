#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  unordered_set<TreeNode*> s;
  TreeNode* dfs(TreeNode* root) {
    if (!root) return root;
    if (s.count(root)) return root;
    auto left = dfs(root->left), right = dfs(root->right);
    if (left && right) return root;
    return left ? left : right;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    s = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
    return dfs(root);
  }
  //   TreeNode* ans = nullptr;
  //   unordered_set<TreeNode*> s;
  //   int dfs(TreeNode* root) {
  //     if (!root) return 0;
  //     int cnt = dfs(root->left) + dfs(root->right) + s.count(root);
  //     if (cnt == s.size() && ans == nullptr) {
  //       ans = root;
  //     }
  //     return cnt;
  //   }

  //  public:
  //   TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes)
  //   {
  //     s = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
  //     dfs(root);
  //     return ans;
  //   }
};