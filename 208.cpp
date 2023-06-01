#include <bits/stdc++.h>
using namespace std;
class Trie {
  struct node {
    vector<node*> next;
    bool leaf;
    node() : leaf(0) { next = vector<node*>(26); }
  };
  node* root;

 public:
  Trie() { root = new node(); }

  void insert(string word) {
    auto cur = root;
    for (int i = 0; word[i]; ++i) {
      int ind = word[i] - 'a';
      if (cur->next[ind] == nullptr) {
        cur->next[ind] = new node();
      }
      cur = cur->next[ind];
    }
    cur->leaf = true;
  }

  bool search(string word) {
    auto cur = root;
    for (int i = 0; word[i]; ++i) {
      int ind = word[i] - 'a';
      if (cur->next[ind] == nullptr) {
        return false;
      }
      cur = cur->next[ind];
    }
    if (cur->leaf == false) {
      return false;
    }
    return true;
  }

  bool startsWith(string prefix) {
    auto cur = root;
    for (int i = 0; prefix[i]; ++i) {
      int ind = prefix[i] - 'a';
      if (cur->next[ind] == nullptr) {
        return false;
      }
      cur = cur->next[ind];
    }
    return true;
  }
};