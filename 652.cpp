#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>>& m) {
    if (!root) return "";
    string ans = "(" + dfs(root->left, m) + to_string(root->val) +
                 dfs(root->right, m) + ")";
    m[ans].push_back(root);
    return ans;
  }

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, vector<TreeNode*>> m;
    vector<TreeNode*> ans;
    dfs(root, m);
    for (auto it = m.begin(); it != m.end(); ++it) {
      if (it->second.size() > 1) ans.push_back(it->second[0]);
    }
    return ans;
  }
};