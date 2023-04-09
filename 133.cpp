#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  unordered_map<Node*, Node*> m;

 public:
  Node* cloneGraph(Node* now) {
    if (!now) return nullptr;
    if (!m.count(now)) {
      m[now] = new Node(now->val);
      for (auto next : now->neighbors) {
        m[now]->neighbors.push_back(cloneGraph(next));
      }
    }
    return m[now];
  }
};