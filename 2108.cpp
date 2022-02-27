#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  bool ispalin(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }

 public:
  string firstPalindrome(vector<string> &words) {
    for (auto &word : words) {
      if (ispalin(word)) return word;
    }
    return "";
  }
};