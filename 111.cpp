#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> que;
    que.push(root);
    int ans = 0;
    while (que.size()) {
      ++ans;
      int size = que.size();
      while (size--) {
        auto temp = que.front();
        que.pop();
        if (!temp->left && !temp->right) return ans;
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
      }
    }
    return 0;
  }
};