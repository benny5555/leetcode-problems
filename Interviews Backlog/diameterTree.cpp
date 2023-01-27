/*Given a root of an N-ary tree, you need to compute the length of the diameter
of the tree.

The diameter of an N-ary tree is the length of the longest path between any two
nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal,
each group of children is separated by the null value.)*/
#include <bits/stdc++.h>

using namespace std;
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};
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