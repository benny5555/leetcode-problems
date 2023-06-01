#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int ans = 1;
    queue<pair<TreeNode*, int>> que;
    que.push(make_pair(root, 0));

    while (que.size()) {
      int n = que.size(), start = que.front().second, end = que.back().second;
      ans = max(ans, end - start + 1);
      for (int i = 0; i < n; ++i) {
        auto temp = que.front();
        int ind = temp.second - start;
        que.pop();
        if (temp.first->left) {
          que.push(make_pair(temp.first->left, (long long)2 * ind + 1));
        }
        if (temp.first->right) {
          que.push(make_pair(temp.first->right, (long long)2 * ind + 2));
        }
      }
    }
    return ans;
  }
};