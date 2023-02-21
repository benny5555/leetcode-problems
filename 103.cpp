#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    while (que.size()) {
      ++depth;
      int n = que.size();
      vector<int> temp;
      for (int i = 0; i < n; ++i) {
        auto node = que.front();
        que.pop();
        temp.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      if (depth % 2 == 0) {
        reverse(temp.begin(), temp.end());
      }
      ans.push_back(temp);
    }
    return ans;
  }
};