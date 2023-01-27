#include <bits/stdc++.h>
using namespace std;
struct Trie {
  bool leaf;
  vector<Trie*> children;
  Trie() : leaf(false), children(26, nullptr) {}
  void insert(const string& s) {
    auto node = this;
    for (auto c : s) {
      c -= 'a';
      if (node->children[c] == nullptr) {
        node->children[c] = new Trie();
      }
      node = node->children[c];
    }
    node->leaf = true;
  }
};
class Solution {
  Trie* root = new Trie();
  bool dfs(const string& s, int start, vector<bool>& vis) {
    if (start == s.size()) return true;
    if (vis[start]) return false;
    vis[start] = true;
    auto node = root;
    int n = s.size();
    for (int i = start; i < n; ++i) {
      node = node->children[s[i] - 'a'];
      if (node == nullptr) return false;
      if (node->leaf && dfs(s, i + 1, vis)) return true;
    }
    return false;
  }

 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(),
         [&](const string& a, const string& b) { return a.size() < b.size(); });
    vector<string> ans;
    for (auto& w : words) {
      vector<bool> vis(w.size());
      if (dfs(w, 0, vis)) {
        ans.push_back(w);
      } else {
        root->insert(w);
      }
    }
    return ans;
  }
};