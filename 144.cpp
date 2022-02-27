#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    while (root) {
      if (root->left) {
        auto pred = root->left;
        while (pred->right && pred->right != root) pred = pred->right;
        if (pred->right == root) {
          pred->right = nullptr;
          root = root->right;
        } else {
          pred->right = root;
          ans.push_back(root->val);
          root = root->left;
        }
      } else {
        ans.push_back(root->val);
        root = root->right;
      }
    }
    return ans;
  }
};