#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
 public:
  int ans = 0;
  int maxDepth(TreeNode* root) {
    if (!root) return ans;
    queue<TreeNode*> que;
    que.push(root);
    while (que.size()) {
      int n = que.size();
      for (int i = 0; i < n; ++i) {
        auto node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      ++ans;
    }
    return ans;
  }
};