#include <bits/stdc++.h>
using namespace std;
class WordDictionary {
  vector<WordDictionary*> next;
  bool leaf;

 public:
  WordDictionary() : next(26), leaf(false) {}

  void addWord(string word) {
    auto cur = this;
    for (int i = 0; word[i]; ++i) {
      auto c = word[i] - 'a';
      if (cur->next[c] == nullptr) {
        cur->next[c] = new WordDictionary();
      }
      cur = cur->next[c];
    }
    cur->leaf = true;
  }

  bool search(string word) {
    auto cur = this;
    for (int i = 0; word[i]; ++i) {
      auto c = word[i];
      if (c == '.') {
        for (auto ch : cur->next) {
          if (ch && ch->search(word.substr(i + 1))) return true;
        }
        return false;
      }
      c -= 'a';
      if (cur->next[c] == nullptr) return false;
      cur = cur->next[c];
    }
    return cur->leaf;
  }
};