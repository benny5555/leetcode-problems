#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  vector<int> ans;
  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->right);
    ans.push_back(root->val);
  }

 public:
  vector<int> postorderTraversal(TreeNode* root) {
    auto head = new TreeNode(0, root, nullptr);
    while (head) {
      if (head->left) {
        auto pred = head->left;
        while (pred->right && pred->right != head) pred = pred->right;
        if (pred->right == head) {
          pred->right = nullptr;
          dfs(head->left);
          head = head->right;
        } else {
          pred->right = head;
          head = head->left;
        }
      } else {
        head = head->right;
      }
    }
    return ans;
  }
};