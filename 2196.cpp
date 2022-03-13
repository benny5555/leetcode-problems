#include <bits/stdc++.h>

#include "leetcode.h"
using namespace std;

class Solution {
  struct node {
    int val;
    bool left;
    node(int v, bool b) : val(v), left(b) {}
  };

 public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    TreeNode* root;
    unordered_map<int, vector<node>> graph;
    unordered_map<int, int> indegree;
    for (auto& d : descriptions) {
      graph[d[0]].push_back(node(d[1], d[2]));
      if (!indegree.count(d[0])) indegree[d[0]] = 0;
      ++indegree[d[1]];
    }
    queue<TreeNode*> que;
    for (auto iter : indegree) {
      if (iter.second == 0) {
        root = new TreeNode(iter.first);
        que.push(root);
      }
    }
    while (que.size()) {
      auto temp = que.front();
      que.pop();
      for (auto& n : graph[temp->val]) {
        if (n.left) {
          temp->left = new TreeNode(n.val);
          que.push(temp->left);
        } else {
          temp->right = new TreeNode(n.val);
          que.push(temp->right);
        }
      }
    }
    return root;
  }
};