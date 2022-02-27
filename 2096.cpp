#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
 private:
  bool dfs(TreeNode* root, int value, string& s) {
    if (!root) return false;
    if (root->val == value) return true;
    if (dfs(root->left, value, s)) {
      s.push_back('L');
    } else if (dfs(root->right, value, s)) {
      s.push_back('R');
    }
    return !s.empty();
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string s, d;
    dfs(root, startValue, s);
    dfs(root, destValue, d);
    while (s.size() && d.size() && s.back() == d.back())
      s.pop_back(), d.pop_back();
    for (int i = 0; s[i]; ++i) s[i] = 'U';
    reverse(d.begin(), d.end());
    return s + d;
  }
};