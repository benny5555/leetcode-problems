#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    queue<TreeNode*> que;
    que.push(root);
    while (que.size()) {
      int n = que.size();
      for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
          ans.push_back(que.front()->val);
        }
        auto temp = que.front();
        que.pop();
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
      }
    }
    return ans;
  }
};