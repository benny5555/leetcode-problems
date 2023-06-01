#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    int i = 0;
    deque<TreeNode*> que;
    que.push_back(root);
    while (i < que.size() && que[i]) {
      que.push_back(que[i]->left);
      que.push_back(que[i]->right);
      ++i;
    }
    while (i < que.size() && !que[i]) {
      ++i;
    }
    return i == que.size();
  }
};