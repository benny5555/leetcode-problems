#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> m;
    int i = 0;
    for (; order[i]; ++i) {
      m[order[i]] = i;
    }
    transform(words.begin(), words.end(), words.begin(), [&](string &a) {
      for (auto &c : a) {
        c = m[c];
      }
      return a;
    });
    return is_sorted(words.begin(), words.end());
  }
};