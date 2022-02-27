#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    unsigned int ans = 1;
    deque<pair<TreeNode*, unsigned int>> que;
    que.push_back({root, 1});
    while (que.size()) {
      int n = que.size();
      auto first = que.front(), last = que.back();
      ans = max(ans, last.second - first.second + 1);
      for (int i = 0; i < n; ++i) {
        auto temp = que.front();
        que.pop_front();
        if (temp.first->left) {
          que.push_back({temp.first->left, 2 * temp.second});
        }
        if (temp.first->right) {
          que.push_back({temp.first->right, 2 * temp.second + 1});
        }
      }
    }
    return ans;
  }
};