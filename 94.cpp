#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    while (root) {
      if (root->left) {
        auto pred = root->left;
        while (pred->right && pred->right != root) pred = pred->right;
        if (pred->right == root) {
          pred->right = nullptr;
          ans.push_back(root->val);
          root = root->right;
        } else {
          pred->right = root;

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