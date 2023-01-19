#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;
class Solution {
  bool dfs(TreeNode* root, int value, string& s) {
    if (!root) return false;
    if (root->val == value) return true;
    if (dfs(root->left, value, s)) {
      s.push_back('L');
    } else if (dfs(root->right, value, s)) {
      s.push_back('R');
    }
    return s.size();
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string start, end;
    dfs(root, startValue, start);
    dfs(root, destValue, end);
    while (start.size() && end.size() && start.back() == end.back()) {
      start.pop_back(), end.pop_back();
    }
    transform(start.begin(), start.end(), start.begin(),
              [](char c) { return c = 'U'; });
    reverse(end.begin(), end.end());
    return start + end;
  }
};