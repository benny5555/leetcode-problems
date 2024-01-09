#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  unordered_map<int, int> m;
  TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir,
                int pl, int pr) {
    if (pl > pr) return nullptr;
    int mid = postorder[pr];
    int ind = m[mid];
    auto root = new TreeNode(mid);
    root->left = dfs(inorder, postorder, il, ind - 1, pl, pl + ind - il - 1);
    root->right = dfs(inorder, postorder, ind + 1, ir, pr - (ir - ind), pr - 1);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      m[inorder[i]] = i;
    }
    return dfs(inorder, postorder, 0, inorder.size() - 1, 0,
               postorder.size() - 1);
  }
};