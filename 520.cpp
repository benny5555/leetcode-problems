#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool iscapital(char c) { return c >= 'A' && c <= 'Z'; }
  bool islower(char c) { return c >= 'a' && c <= 'z'; }
  bool detectCapitalUse(string word) {
    bool start_with_capital = false;
    if (iscapital(word[0])) start_with_capital = true;
    int capital = 0, lower = 0;
    for (int i = 0; i < word.size(); ++i) {
      if (iscapital(word[i])) ++capital;
      if (islower(word[i])) ++lower;
    }
    return lower == word.size() || capital == word.size() ||
           (start_with_capital && lower == word.size() - 1);
  }
};