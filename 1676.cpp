#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  TreeNode* ans = nullptr;
  unordered_set<TreeNode*> s;
  int dfs(TreeNode* root) {
    int cnt = !root ? 0 : s.count(root) + dfs(root->left) + dfs(root->right);
    if (cnt == s.size() && !ans) ans = root;
    return cnt;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    s = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
    dfs(root);
    return ans;
  }
};