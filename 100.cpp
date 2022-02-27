#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};