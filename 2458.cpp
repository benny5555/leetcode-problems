#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  int level[100001]{}, depth[100001]{}, d1[100001], d2[100001]{};
  int dfs(TreeNode* root, int l) {
    if (root == nullptr) return 0;
    level[root->val] = l;
    depth[root->val] = 1 + max(dfs(root->left, l + 1), dfs(root->right, l + 1));
    if (d1[l] < depth[root->val]) {
      d2[l] = d1[l];
      d1[l] = depth[root->val];
    } else if (d2[l] < depth[root->val]) {
      d2[l] = depth[root->val];
    }
    return depth[root->val];
  }

 public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> ans(queries.size());
    dfs(root, 0);
    transform(queries.begin(), queries.end(), ans.begin(), [&](int q) {
      int l = level[q];
      return l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1;
    });
    return ans;
  }
};