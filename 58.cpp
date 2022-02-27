#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int i, j = s.size() - 1;
    while (j >= 0 && s[j] == ' ') --j;
    i = j;
    while (i >= 0 && s[i] != ' ') --i;
    return j - i;
  }
};