#include <bits/stdc++.h>
using namespace std;
struct Trie {
  struct node {
    bool leaf;
    vector<node *> children;
  };
  node *root;
  Trie() {
    root->children.assign(26, nullptr);
    root->leaf = false;
  }
  void insert(const string &word) {
    auto now = root;
    for (auto c : word) {
      c -= 'a';
      if (now->children[c] == nullptr) {
        now->children[c] = new Trie();
      }
      now = now->children[c];
    }
    now->leaf = true;
  }
};