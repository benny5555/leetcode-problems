#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isCircularSentence(string s) {
    if (s[0] != s[s.size() - 1]) return false;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == ' ' && s[i - 1] != s[i + 1]) return false;
    }
    return true;
  }
};