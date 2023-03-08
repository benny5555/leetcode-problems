#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  vector<vector<int>> grid;
  array<Node*, 2> leaf;
  Node* dfs(int x, int y, int s) {
    if (s == 1) {
      return leaf[grid[x][y]];
    }
    s /= 2;
    auto tl = dfs(x, y, s);
    auto tr = dfs(x, y + s, s);
    auto bl = dfs(x + s, y, s);
    auto br = dfs(x + s, y + s, s);
    if (tl == tr && tl == bl && tl == br) {
      return tl;
    }
    return new Node(false, false, tl, tr, bl, br);
  }

 public:
  Node* construct(vector<vector<int>>& g) {
    grid = move(g);
    leaf[0] = new Node(false, true, 0, 0, 0, 0);
    leaf[1] = new Node(true, true, 0, 0, 0, 0);
    return dfs(0, 0, grid.size());
  }
};