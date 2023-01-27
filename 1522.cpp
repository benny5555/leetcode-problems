#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
  int ans = 0;
  int dfs(Node* root) {
    if (root == nullptr) return 0;
    int mmax = 0;
    for (auto next : root->children) {
      int depth = dfs(next);
      ans = max(ans, mmax + depth);
      mmax = max(mmax, depth);
    }
    return mmax + 1;
  }

 public:
  int diameter(Node* root) {
    dfs(root);
    return ans;
  }
};