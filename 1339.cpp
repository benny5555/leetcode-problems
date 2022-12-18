#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  const int mod = 1e9 + 7;
  using ll = long long;
  ll ans = 0, sub = 0, sum = 0;
  int maxProduct(TreeNode* root) {
    sum = s(root);
    s(root);
    return ans % mod;
  }
  int s(TreeNode* root) {
    if (!root) return 0;
    sub = root->val + s(root->left) + s(root->right);
    ans = max(ans, sub * (sum - sub));
    return sub;
  }
};